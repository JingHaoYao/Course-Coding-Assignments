//Jing Hao Yao and Michael Nasselo Assignment 8 Question 2
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void fillCurrParking(ifstream & fin, string currParking[51], int currStatus[51]) // part b
{
	int parkingSpot = 0;
	int isFaculty = 0;
	string name = "";
	while(fin >> isFaculty >> name >> parkingSpot)
	{
		currStatus[parkingSpot] = isFaculty;
		currParking[parkingSpot] = name;
	}
}

void fillAddRemoveParking(ifstream & finAdd, ifstream & finRemove, string addParking[51], string removeParking[51], int addStatus[51]) // part c
{
	int count = 0;
	int isFaculty = 0;
	string name = "";
	while(finAdd >> isFaculty >> name)
	{
		addParking[count] = name;
		addStatus[count] = isFaculty;
		count++;
	}
	count = 0;
	while(finRemove >> isFaculty >> name)
	{
		removeParking[count] = name;
		count++;
	}
}

void removePeople(string name, string currParking[51]){ // part d
	for(int count = 1; count <= 50; count++){
		if(name == currParking[count]){
			currParking[count] = "";
		}
	}
}

int openParkingSpace(int status, string currParking[51]){ // part e
	if(status == 1){
		for(int count = 1; count <= 50; count++){
			if(currParking[count] == ""){
				return count;
			}
		}
		return 0;
	}
	else{
		for(int count = 26; count <= 50; count++){
			if(currParking[count] == ""){
				return count;
			}
		}
		return 0;
	}
}

void assignParkingSpace(string name, int status, string currParking[51], int currStatus[51]){ //part f
	int parkingSpot = openParkingSpace(status,currParking);
	if(parkingSpot != 0){
		currParking[parkingSpot] = name;
		currStatus[parkingSpot] = status;
	}
}

void moveParkingMembers(string currParking[51], string removeParking[51],string addParking[51], int addStatus[51], int currStatus[51]){ //part g
	for(int count = 0; count <= 50; count++){
		removePeople(removeParking[count],currParking);
	}
	for(int parkingSpot = 26; parkingSpot <= 50; parkingSpot++){
		if(currStatus[parkingSpot] == 1){
			assignParkingSpace(currParking[parkingSpot],currStatus[parkingSpot],currParking,currStatus);
			currParking[parkingSpot] = "";
		}
	}
	for(int parkingSpot = 1; parkingSpot <= 50; parkingSpot++){
			assignParkingSpace(addParking[parkingSpot],addStatus[parkingSpot],currParking,currStatus);
	}
}

void outputData(ofstream & fout, string currParking[51], int currStatus[51]){
	for(int count = 1; count <= 50; count++){
		if(currParking[count] != ""){
			fout << currStatus[count] << " " << currParking[count] << " " << count << endl;
		}
	}
}

int main()
{
	ifstream fin1("parking_current.txt");
	ifstream fin2("parking_remove.txt");
	ifstream fin3("parking_add.txt");
	ofstream fout("parkingW19.txt");
	ofstream fout2("parkingtest.txt");
	string currParking[51] = {""};
	string removeParking[51] = {""};
	string addParking[51] = {""};
	int currStatus[51] = {0};
	int addStatus[51] = {0};
	int removeStatus[51] = {0};	
	
	if(!fin1 || !fin2 || !fin3){
		cout << "Error!";
		return EXIT_FAILURE;
	}
	
	fillCurrParking(fin1,currParking,currStatus);
	fillAddRemoveParking(fin3,fin2,addParking,removeParking,addStatus);
	for(int count = 1; count <= 50; count++){
		fout2 << currParking[count];
	}
	moveParkingMembers(currParking,removeParking,addParking,addStatus,currStatus);
	outputData(fout,currParking, currStatus);
	fin1.close();
	fin2.close();
	fin3.close();
	fout.close();
	fout2.close();
	system("pause");
	return EXIT_SUCCESS;
}

/*
Output:
1 Xie_Wei-Chau 1
1 Hulls_Carol 2
1 Pritzker_Mark 3
1 Fluid_Newtonian 4
0 Rochlitz_Alexandra 5
1 Manezes_Alfred 6
1 Tuncel_Levent 7
1 McKinnon_David 8
1 Davison_Dan 11
1 Bedi_Sanjeev 12
0 Malloch_Jeremy 19
1 McKillop_Bob 21
1 Davidson_George 25
0 Lung_Ian 26
0 Tan_Mark 27
0 Huot_Isabella 28
0 Lau_Amanda 29
0 Roller_Anika 30
0 Mills_Joel 31
0 Starratt_Kathryn 32
0 Belisle_Matt 33
0 Wang_Willian 34
0 Jasmine_Princess 35
0 Samlalsingh_Ryan 36
0 Yuan_Jacky 37
0 Barakat_Abdullah 38
0 Ratiu_Timea 39
0 Hamza_Muhammad 40
0 Zheng_Tim 41
0 Sheng_Stephen 42
0 Kim_Leo 43
0 Clifford_Zachary 44
0 Bhamare_Yash 45
0 Kandathil_Ashar 46
0 Yousufzay_Namoos 47
0 Keillor_Peter 48
0 Lau_Darren 49
0 Eltantawy_Mostafa 50
*/
