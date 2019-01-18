// Jing Hao Yao and Jacob Piirsalu Assignment 5 Question 3
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int getMinutes(int rawTime){
	int numHours = 0;
	int numMinutes = 0;
	int totalMinutes = 0;
	numMinutes = rawTime % 100;
	numHours = rawTime - numMinutes;
	totalMinutes = numHours*60 + numMinutes;
	return totalMinutes;
}

double getDistance(double xCoord, double yCoord){ 
	double distance = 0;
	distance = sqrt(pow(xCoord,2) + pow(yCoord,2));
	return distance;
}

double getHeading(double xCoord, double yCoord){
	double headingDeg= atan(yCoord/xCoord)*(180/M_PI);
	if(xCoord < 0 && yCoord == 0){
		headingDeg = 180;
	}
	return headingDeg;
}

int main() {
	ifstream fin("wascally_wabbits.txt");
	ofstream fout("rabbitOutput.txt");
	double xCoord = 0;
	double yCoord = 0;
	int rawTime = 0;	
	int shortestTimeRabbits = 9999;
	int distanceToRabbit;
	int headingToRabbit;
	int minutesSpottedRabbit;
	int rabbitNumber = 0;
	int oldTimeRabbits = 0;
	int timeBetweenRabbits = 0;
	while(fin >> rawTime >> xCoord >> yCoord){
		rabbitNumber++;
		timeBetweenRabbits = getMinutes(rawTime) - oldTimeRabbits;
		fout << "Number: " << rabbitNumber << " Distance: " << getDistance(xCoord, yCoord) << " Heading: " << getHeading(xCoord, yCoord) << " Degrees" << endl;
		oldTimeRabbits = getMinutes(rawTime);
		if(timeBetweenRabbits < shortestTimeRabbits){
			shortestTimeRabbits = timeBetweenRabbits;
		}
	}
	fout << "Shortest Time Between Rabbits: " << shortestTimeRabbits << " minutes." << endl;
}

/* Output File:
Number: 1 Distance: 82.7497 Heading: -5.26965 Degrees
Number: 2 Distance: 76.8404 Heading: -7.40248 Degrees
Number: 3 Distance: 121.006 Heading: -5.73886 Degrees
Number: 4 Distance: 121.058 Heading: -5.97432 Degrees
Number: 5 Distance: 217.003 Heading: 0.31684 Degrees
Number: 6 Distance: 64.0095 Heading: -0.984674 Degrees
Number: 7 Distance: 36.3593 Heading: -21.6258 Degrees
Number: 8 Distance: 306.025 Heading: 0.730201 Degrees
Number: 9 Distance: 10.5152 Heading: -57.8213 Degrees
Number: 10 Distance: 272.469 Heading: 2.54527 Degrees
Number: 11 Distance: 42.6821 Heading: 10.2568 Degrees
Number: 12 Distance: 19.7231 Heading: -22.6646 Degrees
Number: 13 Distance: 37.1849 Heading: -11.7934 Degrees
Number: 14 Distance: 291.399 Heading: 1.4945 Degrees
Number: 15 Distance: 64.0095 Heading: -0.984674 Degrees
Number: 16 Distance: 10.5152 Heading: 57.8213 Degrees
Number: 17 Distance: 19.7231 Heading: 22.6646 Degrees
Number: 18 Distance: 42.6821 Heading: 10.2568 Degrees
Number: 19 Distance: 2.2 Heading: 90 Degrees
Number: 20 Distance: 13 Heading: 180 Degrees
Number: 21 Distance: 2.2 Heading: 0 Degrees
Number: 22 Distance: 2.2 Heading: -90 Degrees
Shortest Time Between Rabbits: 5 minutes.
*/
