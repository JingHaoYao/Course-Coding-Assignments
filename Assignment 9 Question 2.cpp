#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void fillCoffeeData(ifstream & fin, int coffeeData[10][5])
{
	int temperature = 0;
	int grindRating = 0;
	int tasty = 0;
	
	while(fin >> temperature >> grindRating >> tasty){
		coffeeData[temperature - 90][grindRating] = tasty;
	}
}

void aggCoffeeDataConvert(int coffee1Data[10][5], int coffee2Data[10][5], int coffee3Data[10][5], double aggCoffee[10][5])
{
	double aggDataEntry = 0;
	for(int row = 1; row <= 4; row++){
		for(int column = 1; column <= 9; column++){
			aggDataEntry = (coffee1Data[column][row] + coffee2Data[column][row] + coffee3Data[column][row])/3.0;
			aggCoffee[column][row] = aggDataEntry;
		}
	}
}

void outputCoffeeData(double coffeeData[10][5])
{
	cout << setw(28) << "Rating of Coffee" << endl;
	cout << setw(25) << "Temperature" << endl;
	cout << " ";
	for(int temp = 1; temp <= 9; temp++){
		cout << setw(7) << temp + 90;
	}
	cout << endl;
	for(int row = 1; row <= 4; row++){
		cout << row;
		for(int column = 1; column <= 9; column++){
			cout << setw(7) << setprecision(3) << coffeeData[column][row];
		}
		cout << endl;
	}
	cout << endl <<  setw(20) << "Fineness Grading on the Left Side" << endl;
}

double sumRatings(double coffeeData[10][5], bool isRow, int index){
	double sumOfRatings = 0;
	if(isRow == true){
		for(int column = 1; column <= 4; column++){
			sumOfRatings += coffeeData[column][index];
		}
	}
	else{
		for(int row = 1; row <= 4; row++){
			sumOfRatings += coffeeData[index][row];
		}
	}
	
	return sumOfRatings;
}

void findBest(double coffeeData[10][5], int & bestCoarseness, int & bestTemperature)
{
	double rating = 0;
	double maxRating = 0;
	
	int bestC = 0;
	int bestT = 0;
	for(int row = 1; row <= 4; row++){
		rating = sumRatings(coffeeData,true,row);
		if(rating >= maxRating){
			maxRating = rating;
			bestC = row;
		}
	}
	maxRating = 0;
	for(int column = 1; column <= 9; column++){
		rating = sumRatings(coffeeData,false,column);
		if(rating >= maxRating){
			maxRating = rating;
			bestT = column;
		}
	}
	
	bestCoarseness = bestC;
	bestTemperature = bestT;
}

int main(){
	ifstream fin1("coffee1.txt");
	ifstream fin2("coffee2.txt");
	ifstream fin3("coffee3.txt");
	int bestTemp = 0;
	double sumTempRating = 0;
	double maxTempRating = 0;
	int bestCoarseness = 0;
	int bestTemperature = 0;
	int coffee1Data[10][5] = {0};
	int coffee2Data[10][5] = {0};
	int coffee3Data[10][5] = {0};
	double aggCoffeeData[10][5] = {0};
	
	fillCoffeeData(fin1,coffee1Data);
	fillCoffeeData(fin2,coffee2Data);
	fillCoffeeData(fin3,coffee3Data);
	aggCoffeeDataConvert(coffee1Data,coffee2Data,coffee3Data,aggCoffeeData);
	outputCoffeeData(aggCoffeeData);
	
	for(int column = 1; column <= 9; column++){
		sumTempRating = sumRatings(aggCoffeeData,false,column);
		if(sumTempRating > maxTempRating){
			maxTempRating = sumTempRating;
			bestTemp = column + 90;
		}
	}
	cout << "The best temperature is: " << bestTemp << endl;
	findBest(aggCoffeeData,bestCoarseness,bestTemperature);
	cout << "The best temperature and coarseness are: " << bestTemperature + 90 << " and " << bestCoarseness << endl;
	
	system("pause");
	return EXIT_SUCCESS;
}

/*
Output:
            Rating of Coffee
              Temperature
      91     92     93     94     95     96     97     98     99
1   3.33   5.67   5.67   4.33   4.33      5      5   5.33   8.33
2      7   2.33      9      4      5   4.67   9.33   5.33   4.67
3      4      6   6.33   3.67   6.33   4.67      4   5.33      4
4      6   3.67   5.67      5      7      5      6   6.33      6

Fineness Grading on the Left Side
The best temperature is: 93
The best temperature and coarseness are: 93 and 2
Press any key to continue . . .
*/
