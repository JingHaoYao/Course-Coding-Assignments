// Jing Hao Yao
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	int whatPerson = 0;
	int typeOfBook = 0;
	ofstream fout("output.txt");
	ifstream fin("input.txt");
	int testCases = 0;
	
	if(!fin){
		cout << "no file!";
		system("pause");
		return EXIT_FAILURE;
	}
		
while(fin >> whatPerson and fin >> typeOfBook){
	fout << "Enter 0 if you are a staff, 1 if you are a student, and 2 if you are a student." << endl;
	fout << "If you want to borrow: A book - enter 0, A journal - enter 1, An electronic - enter 2." << endl;

	if(whatPerson == 0){
		fout << "As a staff,";
		if(typeOfBook == 0){
			fout << " you can borrow an unlimited number of journals for the term."<< endl;
		}
		else if(typeOfBook == 1){
			fout << " you can borrow an unlimited number of journals for two weeks."<< endl;
		}
		else{
			fout << " you can borrow an unlimited number of electronics without time limits."<< endl;
		}
	}
	else if(whatPerson == 1){
		fout << "As a student,";
		if(typeOfBook == 0){
			fout << " you can borrow an unlimited number of journals for two weeks."<< endl;
		}
		else if(typeOfBook == 1){
			fout << " you can borrow an unlimited number of journals for two weeks."<< endl;
		}
		else{
			fout << " you can borrow an unlimited number of electronics without time limits."<< endl;
		}
	}
	else{
		fout << "As an alumni,";
		if(typeOfBook == 0){
			fout << " you can borrow up to 20 journals for two weeks."<< endl;
		}
		else if(typeOfBook == 1){
			fout << " you cannot borrow journals."<< endl;
		}
		else{
			fout << " you cannot borrow electronics."<< endl;
		}
	}
	testCases++;
}
	fout << "There are " << testCases << " test cases.";
	fin.close();
	fout.close();	
	system("pause");
	return EXIT_SUCCESS;
}

/* Input File: 
2 2 1 2 0 2 1 0 2 1

Output File: 
Enter 0 if you are a staff, 1 if you are a student, and 2 if you are a student.
If you want to borrow: A book - enter 0, A journal - enter 1, An electronic - enter 2.
As an alumni, you cannot borrow electronics.
Enter 0 if you are a staff, 1 if you are a student, and 2 if you are a student.
If you want to borrow: A book - enter 0, A journal - enter 1, An electronic - enter 2.
As a student, you can borrow an unlimited number of electronics without time limits.
Enter 0 if you are a staff, 1 if you are a student, and 2 if you are a student.
If you want to borrow: A book - enter 0, A journal - enter 1, An electronic - enter 2.
As a staff, you can borrow an unlimited number of electronics without time limits.
Enter 0 if you are a staff, 1 if you are a student, and 2 if you are a student.
If you want to borrow: A book - enter 0, A journal - enter 1, An electronic - enter 2.
As a student, you can borrow an unlimited number of journals for two weeks.
Enter 0 if you are a staff, 1 if you are a student, and 2 if you are a student.
If you want to borrow: A book - enter 0, A journal - enter 1, An electronic - enter 2.
As an alumni, you cannot borrow journals.
There are 5 test cases. */
