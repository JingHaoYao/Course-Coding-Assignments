#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isEqualInTol(double X, double Y, double TOL){
	if(fabs(X-Y) <= TOL){
		return true;
	}
	return false;
}

double logOutput(double X, double B){
	return log10(X)/log10(B);
}

double convertToRad(double angleDeg){
	return (angleDeg*M_PI)/180;
}

double cosineLawLength(double angleDeg, double length1, double length2){
	return sqrt(pow(length1,2)+pow(length2,2) - 2*length1*length2*cos(convertToRad(angleDeg)));
}

int main(){
	double tolX = 0, tolY = 0, TOL = 0, logX = 0, logB = 0,
		   angleDeg = 0, closedAngle = 0, triLength1 = 0,
		   triLength2 = 0;
		   
	cout << "Input 2 numbers X and Y along with a tolerance." << endl;
	cin >> tolX >> tolY >> TOL;
	if(isEqualInTol(tolX,tolY,TOL)){
		cout << "The two numbers are equal within tolerance." << endl;
	}
	else{
		cout << "The two numbers are not equal within tolerance." << endl;
	}
	
	cout << "Enter an argument X and a base B for a logarithm." << endl;
	cin >> logX >> logB;
	while(logX <= 0 || logB <= 0 || logB == 1){
		cout << "Please enter another argument and base." << endl;
		cin >> logX >> logB;
	}
	cout << "Your log value is: " << logOutput(logX,logB) << endl;
	
	cout << "Enter an angle in degrees" << endl;
	cin >> angleDeg;
	cout << "That angle in rad is: " << convertToRad(angleDeg) << endl;
	
	cout << "Enter a angle in degrees closed within two sides and the lengths of the two sides" << endl;
	cin >> closedAngle >> triLength1 >> triLength2;
	while(closedAngle >= 180 || closedAngle <= 0 || triLength1 <= 0 || triLength2 <= 0){
		cout << "Please enter another angle and two different side lengths." << endl;
		cin >> closedAngle >> triLength1 >> triLength2;
	}
	cout << "The length of the third side is: " << cosineLawLength(closedAngle,triLength1,triLength2) << endl;
	system("pause");
	return EXIT_SUCCESS;
}

/*
Test Run:
Input 2 numbers X and Y along with a tolerance.
0.3 0.5 0.2
The two numbers are equal within tolerance.
Enter an argument X and a base B for a logarithm.
-1 -1
Please enter another argument and base.
-1 0
Please enter another argument and base.
2 0
Please enter another argument and base.
0 54
Please enter another argument and base.
2 4
Your log value is: 0.5
Enter an angle in degrees
270
That angle in rad is: 4.71239
Enter a angle in degrees closed within two sides and the lengths of the two sides
-180 0 1
Please enter another angle and two different side lengths.
180 2 5
Please enter another angle and two different side lengths.
150 0 -1
Please enter another angle and two different side lengths.
150 0 4
Please enter another angle and two different side lengths.
150 4 6
The length of the third side is: 9.67312
Press any key to continue . . .
*/
