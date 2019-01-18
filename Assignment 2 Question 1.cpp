// Jing Hao Yao Assumptions: User inputs a two decimal number within a reasonable range for a coffee and a snack
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	double amountMoney = 0;
	cout << "How much money do you have in dollars to two decimal digits?" << endl;
	cin >> amountMoney;
	cout << "You have $" << amountMoney << "." << endl;
	
	if(amountMoney < 0.9){
		cout << "You will not buy a coffee ";
	}
	else if(amountMoney < 1.2){
		cout << "You will buy a small coffee ";
		amountMoney -= 0.9;
	}
	else{
		cout << "You will buy a regular coffee ";
		amountMoney -= 1.2;
	}
	
	if(amountMoney < 0.5){
		cout << "and you will buy no sweet.";
	}
	else if(amountMoney < 0.6){
		cout << "and you will buy a mini tart.";
	}
	else if(amountMoney < 1){
		cout << "and you will buy a chocolate.";
	}
	else{
		cout << "and you will buy a donut.";
	}
	
	return 0;
}

/* Test 1: Let us test if 0.89 will say that I can only buy a chocolate and nothing else.
	Expected Outcome: The code will say I will not buy a coffee but will but a chocolate. 
	Code Output:
	How much money do you have in dollars to two decimal digits?
	0.89
	You have $0.89.
	You will not buy a coffee and you will buy a chocolate.
	Outcome Successful: Yes, as it outputed that I will only buy a chocolate, the most expensive sweet considering what I have.
	
	Test 2:Let us test if 1.00 will say that I can only buy a small coffee.
	Expected Outcome: The code will output that I will only buy a small coffee.
	Code Output:
	How much money do you have in dollars to two decimal digits?
	1.00
	You have $1.
	You will buy a small coffee and you will buy no sweet.
	Outcome Successful: Yes, as it outputed that I can only buy a small coffee, which follows the rule that mike buys the most expensive coffee he can first.
	
	Test 3: Let us test if 2.20 will say that I can buy both a donut and a regular coffee.
	Expected Outcome: The code will output that I will buy both a donut and a regular coffee.
	Code Output:
	How much money do you have in dollars to two decimal digits?
	2.2
	You have $2.2.
	You will buy a regular coffee and you will buy a donut.
	Outcome Successful: Yes, as it outputed that I can spend both $1.2 on a reg coffee (the most expensive coffee) and the remaining $1.00 on the donut (which is the most expensive sweet after buying coffee).
	*/ 
