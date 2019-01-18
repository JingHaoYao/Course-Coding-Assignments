// Jing Hao Yao
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
int angle;
double d;

int main(){
	cout << "Hey hey enter an angle in degrees." << endl;
	cin >> angle;
	
	d = cos((float(angle)*M_PI)/180)*cos((float(angle)*M_PI)/180) + sin((float(angle)*M_PI)/180)*sin((float(angle)*M_PI)/180) - 1;
	if(d == 0){
		cout << "Yes, d calculates to 0 for when the angle is a float." << endl;
	}
	if(d != 0){
		cout << "No, d does not calculate to 0 for when the angle is a float." << endl;
	}
	d = cos((double(angle)*M_PI)/180)*cos((double(angle)*M_PI)/180) + sin((double(angle)*M_PI)/180)*sin((double(angle)*M_PI)/180) - 1;
	if(d == 0){
		cout << "Yes, d calculates to 0 for when the angle is a double." << endl;
	}
	if(d != 0){
		cout << "No, d does not calculate to 0 for when the angle is a double." << endl;
	}
	d = cos(((long double)angle*M_PI)/180)*cos(((long double)angle*M_PI)/180) + sin(((long double)angle*M_PI)/180)*sin(((long double)angle*M_PI)/180) - 1;
	if(d == 0){
		cout << "Yes, d calculates to 0 for when the angle is a long double." << endl;
	}
	if(d != 0){
		cout << "No, d does not calculate to 0 for when the angle is a long double." << endl;
	}
}

/* 
Test Case 1;
Hey hey enter an angle in degrees.
10
No, d does not calculate to 0 for when the angle is a float.
No, d does not calculate to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.

Test Case 2:
Hey hey enter an angle in degrees.
15
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.

Test Case 3:
Hey hey enter an angle in degrees.
67
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.

Test Case 4:
Hey hey enter an angle in degrees.
89
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
No, d does not calculate to 0 for when the angle is a long double.

Test Case 5:
Hey hey enter an angle in degrees.
-40
No, d does not calculate to 0 for when the angle is a float.
No, d does not calculate to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.

Test Case 6:
Hey hey enter an angle in degrees.
356
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.

Test Case 7:
Hey hey enter an angle in degrees.
230
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.

Test Case 8:
Hey hey enter an angle in degrees.
182
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
No, d does not calculate to 0 for when the angle is a long double.

Test Case 9:
Hey hey enter an angle in degrees.
248
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.

Test Case 10:
Hey hey enter an angle in degrees.
0
Yes, d calculates to 0 for when the angle is a float.
Yes, d calculates to 0 for when the angle is a double.
Yes, d calculates to 0 for when the angle is a long double.
*/
