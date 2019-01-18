// Jing Hao Yao
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double angle = 0;
double length = 0;
double xCoord = 0;
double yCoord = 0;

int main(){
	cout << "Enter an angle in degrees." << endl;
	cin >> angle;
	cout << "Enter a length." << endl;
	cin >> length;
	yCoord = length*sin((angle*M_PI)/180);
	xCoord = length*cos((angle*M_PI)/180);
	cout << "The coordinates of the end effector are (" << xCoord << ", " << yCoord << ")." << endl;
	return 0;
}

/* Test Case 1 Output:
Enter an angle in degrees.
45
Enter a length.
1
The coordinates of the end effector are (0.707107, 0.707107).

Test Case 2 Output:
Enter an angle in degrees.
110
Enter a length.
2.5
The coordinates of the end effector are (-0.85505, 2.34923).

Test Case 3 Output:
Enter an angle in degrees.
-30
Enter a length.
1
The coordinates of the end effector are (0.866025, -0.5).
*/
