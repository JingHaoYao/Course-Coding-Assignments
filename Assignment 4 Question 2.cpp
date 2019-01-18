// Jing Hao Yao
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
	ifstream fin("taxi.txt");
	int tripNumber;
	int returnTrip =0;
	int numStops = 0;
	double currXCoord = 0;
	double currYCoord = 0;
	double oldXCoord = 0;
	double oldYCoord = 0;
	double tempDistance = 0;
	double totalTripDistance = 0;
	double tripCost = 0;
	double culmTripDistance = 0;
	double culmTripCost = 0;
	double leastTripCost = 8999;
	double maxTripDistance = 0;
	int doubleDigits = 11;
	
	if(!fin){
		cout << "no file!";
		system("pause");
		return EXIT_FAILURE;
	}
	
	cout << "Trip" << setw(11) << "Return" << setw(9) << "Stops" << setw(12) << "Distance" << setw(8) << "Cost" << setw(23) 
	<< "Cumulative Distance" << setw(20) << "Cumulative Cost" << endl;
	while(fin >> returnTrip >> numStops){
		oldXCoord = 0;
		oldYCoord = 0;
		currXCoord = 0;
		currYCoord = 0;
		totalTripDistance = 0;
		for(int stopNumber = 0;stopNumber < numStops; stopNumber++){
			oldXCoord = currXCoord;
			oldYCoord = currYCoord;
  			fin >> currXCoord >> currYCoord;
  			tempDistance = sqrt(pow((currXCoord - oldXCoord),2)+pow((currYCoord - oldYCoord),2));
			totalTripDistance += tempDistance;
		}
		if(returnTrip == 1){
			tempDistance = sqrt(pow(currXCoord,2) + pow(currYCoord,2));
			totalTripDistance += tempDistance;
		}
		tripNumber++;
		tripCost = totalTripDistance*2.7 + numStops*11;
		culmTripDistance += totalTripDistance;
		culmTripCost += tripCost;
		if(tripNumber < 10){
			doubleDigits = 11;
		}
		else{
			doubleDigits = 10;
		}
		
		if(tripNumber < 8 || (tripNumber - 7)%10 == 0){
		cout << tripNumber << setw(doubleDigits) << returnTrip << setw(9) << numStops << setw(12) << fixed << setprecision(2) 
		<< totalTripDistance << setw(12) << setprecision(2) << fixed << tripCost << setw(19) << setprecision(2) << fixed 
		<< culmTripDistance << setw(18) << setprecision(2) << fixed << culmTripCost
		<< endl;
		}
		else{
		}
		
		if(maxTripDistance < totalTripDistance){
			maxTripDistance = totalTripDistance;
		}
		else {
		}
		
		if(leastTripCost > tripCost){
			leastTripCost = tripCost;
		}
		else{
		}
	}
	cout << endl;
	cout << "Culminating Distance of August: " << culmTripDistance << endl;
	cout << "Culminating Amount Collected in August: " << culmTripCost << endl;
	cout << "Longest Trip Taken by Water Taxi: " << maxTripDistance << endl;
	cout << "Least Expensive Trip: " << leastTripCost << endl;
	cout << endl;
	system("pause");
}

/*
Trip     Return    Stops    Distance    Cost    Cumulative Distance     Cumulative Cost
1          0        1       10.20       38.54              10.20             38.54
2          1        2       12.00       54.40              22.20             92.94
3          0        4       32.84      132.67              55.04            225.61
4          0        3       21.03       89.78              76.07            315.40
5          0        5       29.52      134.71             105.60            450.11
6          1        7       51.39      215.76             156.99            665.87
7          0        2       10.64       50.74             167.63            716.60
17         0        5       32.35      142.34             428.67           1817.42
27         0        3       26.75      105.21             712.19           2912.91
37         0        2       16.65       66.96             949.68           3884.15
47         1        2       11.93       54.21            1182.91           4832.85
57         0        2       24.18       87.28            1434.52           5820.19
67         0        4       30.23      125.61            1642.94           6690.93
77         0        1        7.73       31.88            1846.99           7472.87

Culminating Distance of August: 1871.36
Culminating Amount Collected in August: 7571.68
Longest Trip Taken by Water Taxi: 51.39
Least Expensive Trip: 23.44

Press any key to continue . . .

*/



