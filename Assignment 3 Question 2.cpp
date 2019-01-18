// Jing Hao Yao
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	ifstream fin("A3Actual.txt");
	double robotArmLength = 0;
	double xCoord = 0;
	double yCoord = 0;
	double calcOutcome;
	int numPointsNoReach = 0;
	
	if(!fin){
		cout << "no file!";
		system("pause");
		return EXIT_FAILURE;
	}
	
	cout << "What is the length of the robot arm?" << endl;
	fin >> robotArmLength;
	
	while(fin >> xCoord and fin >> yCoord){
		calcOutcome = sqrt(xCoord*xCoord + yCoord*yCoord);
		if (fabs(calcOutcome - robotArmLength) > 0.1){
			numPointsNoReach++;
		}
	}
	cout << "The robot could not reach " << numPointsNoReach << " points." << endl;
	fin.close();	
	system("pause");
	return EXIT_SUCCESS;
}

/*
What is the length of the robot arm?
The robot could not reach 8 points.
*/

