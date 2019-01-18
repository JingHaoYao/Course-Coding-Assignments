// Jing Hao Yao Assignment 10 Question 1
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int const MAXTASKNUM = 9;

class task
{
	private:
	int startTime, numHoursWork;
	string taskName;
	
	public:
		task()
		{
			startTime = 0;
			numHoursWork = 0;
			taskName = "";	
		}
		
		task(int startTime0, int numHoursWork0, string taskName0)
		{
			setStartTime(startTime0);
			setWorkHours(numHoursWork0);
			taskName = taskName0;
		}
		
		int getStartTime()
		{
			return startTime;
		}
		
		int getWorkHours()
		{
			return numHoursWork;
		}
		
		string getTaskName(){
			return taskName;
		}
		
		void setStartTime(int startTime0)
		{
			startTime = abs(startTime0);
		}
		
		void setWorkHours(int numHoursWork0)
		{
			numHoursWork = abs(numHoursWork0);
		}
		
		void setTaskName(string taskName0)
		{
			taskName = taskName0;
		}
		
		int whatEndTime()
		{
			return startTime + (numHoursWork * 100);	
		}
		
		bool isTaskTooLong(){
			if(whatEndTime() > 1700) 
			{
				return true;
			} 
			return false;
		}
		
		bool tasksConflict(task & other)
		{
			//Conflicting means that the startTime of one task earlier than the end time of another task	
			if(taskName != "" && other.getTaskName() != ""){
				if(whatEndTime() > other.startTime)
				{
					return true;
				}
				else
				{
					return false;
				}	
			}
			return false;
		}
		
		void outputTask(bool isLate){
			if(taskName != ""){
				cout << "Task Name: " << setw(18) << taskName << " StartTime: " << setw(4) << startTime << setw(4) << " EndTime: "<< whatEndTime();
				if(isLate == true)
				{
					cout << " LATE";
				} 
				cout << endl;	
			}
		}
		
		void readIn(istream & in)
		{
			in >> taskName >> startTime >> numHoursWork;
			if(startTime < 800)
			{
				setStartTime(800);
			}
		}
		
		friend istream & operator >> (istream & in, task & t0);
		friend ostream & operator << (ostream & out, task const & t0);
};

istream & operator >> (istream & in, task & t0)
{
	in >> t0.taskName >> t0.startTime >> t0.numHoursWork;
	return in;
}

ostream & operator << (ostream & out, task const & t0)
{
	out << t0.taskName << " " << t0.startTime << " " << t0.numHoursWork;
}

void storeArray(ifstream & fin, task taskList[MAXTASKNUM])
{
	for(int taskNum = 0; taskNum < MAXTASKNUM; taskNum++)
	{
		taskList[taskNum].readIn(fin);
	}
}

int main(){
	ifstream fin("mike_tasks_easy.txt");
	task taskList[MAXTASKNUM] = task();
	int numConflicts = 0;
	
	storeArray(fin, taskList);
	for(int taskNum = 0; taskNum < MAXTASKNUM; taskNum++)
	{
		taskList[taskNum].outputTask(taskList[taskNum].isTaskTooLong());
	}
	
	for(int taskNum = 0; taskNum < MAXTASKNUM; taskNum++)
	{
		if(taskList[taskNum].tasksConflict(taskList[taskNum + 1]))
		{
			numConflicts++;
		}
	}
	cout << "Number of Conflicts: " << numConflicts << endl;
	fin.close();
	system("pause");
}

/*
Task Name:        check_email StartTime:  800 EndTime: 900
Task Name:           Walk_dog StartTime:  800 EndTime: 1000
Task Name:       Write_emails StartTime: 1100 EndTime: 1300
Task Name:    MTE100_planning StartTime: 1200 EndTime: 1400
Task Name:      spin_in_chair StartTime: 1300 EndTime: 1400
Task Name:              lunch StartTime: 1300 EndTime: 1400
Task Name:            meeting StartTime: 1400 EndTime: 1700
Number of Conflicts: 4
Press any key to continue . . .
*/
