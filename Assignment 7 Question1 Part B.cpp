#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	ifstream fin("RGBResults.txt");
	string colorName = "";
	int redValue = 0, greenValue = 0, blueValue = 0;
	double redTotalP = 0, greenTotalP = 0, blueTotalP = 0;
	double maxRedP = 0, maxGreenP = 0, maxBlueP = 0;
	double redTotalO = 0, greenTotalO = 0, blueTotalO = 0;
	double maxRedO = 0, maxGreenO = 0, maxBlueO = 0;
	int countP = 0;
	int countO = 0;
	
	if(!fin){
		cout << "File not opened correctly";
		return EXIT_FAILURE;
	}
	
	while(fin >> colorName){
		if(colorName == "Pink"){
			fin >> redValue >> greenValue >> blueValue;
			redTotalP += redValue;
			greenTotalP += greenValue;
			blueTotalP += blueValue;
			countP++;
			if(redValue > maxRedP){
				maxRedP = redValue;
			}
			if(greenValue > maxGreenP){
				maxGreenP = greenValue;
			}
			if(blueValue > maxBlueP){
				maxBlueP = blueValue;
			}
		}
		else{
			fin >> redValue >> greenValue >> blueValue;
			redTotalO += redValue;
			greenTotalO += greenValue;
			blueTotalO += blueValue;
			countO++;
			if(redValue > maxRedO){
				maxRedO = redValue;
			}
			if(greenValue > maxGreenO){
				maxGreenO = greenValue;
			}
			if(blueValue > maxBlueO){
				maxBlueO = blueValue;
			}
		}
	}
	cout << "The average RGB values respectively for pink are: " << redTotalP/countP << " " << greenTotalP/countP
		 << " " << blueTotalP/countP << endl;
	cout << "The max RGB values respectively for pink are: " << maxRedP << " " << maxGreenP << " " << maxBlueP << endl;
	cout << "The average RGB values respectively for pink are: " << redTotalO/countO << " " << greenTotalO/countO
		 << " " << blueTotalO/countO << endl;
	cout << "The max RGB values respectively for pink are: " << maxRedO << " " << maxGreenO << " " << maxBlueO << endl;
	fin.close();
	system("pause");
	return EXIT_SUCCESS;
}
