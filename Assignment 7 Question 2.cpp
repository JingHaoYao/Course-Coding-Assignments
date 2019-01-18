#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double averageOfGrades(ifstream & fin) {
	double gradePercent = 0;
	int numEntries = 0;
	double total = 0;
		
	while(fin >> gradePercent){
		if(gradePercent >= 100){
			total += 100;
			numEntries++;
		}
		else if(gradePercent < 0){

		}
		else{
			total += gradePercent;
			numEntries++;
		}
	}
	return total/numEntries;
}
	
void sortEntries(double & entry1, double & entry2, double & entry3){
	if(entry1 > entry2){
		int temp = entry2;
		entry2 = entry1;
		entry1 = temp;
	}
		
	if(entry2 > entry3){
		int temp = entry3;
		entry3 = entry2;
		entry2 = temp;
	}
	
	if(entry1 > entry2){
		int temp = entry2;
		entry2 = entry1;
		entry1 = temp;
	}
}

void outputData(ofstream & fout, double entry1, double entry2, double entry3){
	sortEntries(entry1,entry2,entry3);
	fout << entry1 << endl << entry2 << endl << entry3 << endl;
}

	
int main(){
	ifstream fin1("A1.txt");
	ifstream fin2("A2.txt");
	ifstream fin3("A3.txt");
	ofstream fout("Results.txt");
	double average1 = 0, average2 = 0, average3 = 0;
	
	if(!fin1 || !fin2 || !fin3){
		cout << "Files not opened properly.";
		return EXIT_FAILURE;
	}
	
	average1 = averageOfGrades(fin1);
	average2 = averageOfGrades(fin2);
	average3 = averageOfGrades(fin3);
	outputData(fout,average1,average2,average3);
	fin1.close();
	fin2.close();
	fin3.close();
	fout.close();
	system("pause");
	return EXIT_SUCCESS;
}

