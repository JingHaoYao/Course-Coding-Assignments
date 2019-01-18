#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Fraction
{
	private:
		int numerator, denominator;
		
	public:
		Fraction(){
			numerator = 0;
			denominator = 1;
		}
		Fraction(int nume, int denom){
			setFraction(nume,denom);
		}
		
		void setFraction(int nume0, int denom0){
			if(fabs((double)nume0/denom0) < 1){
				numerator = nume0;
				denominator = denom0;
			}
		}
		
		int getNume(){
			return numerator;
		}
		
		int getDenom(){
			return denominator;
		}
		
		double approxFraction(int digits) const
		{
			double fraction0 = (double)numerator/denominator;
			double decimalPlaces = fraction0 - round(fraction0);
			return round(fraction0) + (round(decimalPlaces * pow(10,digits)))/pow(10,digits);
		}
		
		bool isExactlySame(Fraction const & other) const
		{
			if(numerator == other.numerator && denominator == other.denominator){
				return true;
			}
			else{
				return false;
			}
		}
		
		void output(int digits0, Fraction const & other) const
		{
			cout << numerator << " " << denominator << " " << approxFraction(digits0) << " ";
			if(isExactlySame(other)){
				cout << "Is same" << endl;
			}
			else{
				cout << "Not same" << endl;
			}
		}
};

int main(){
	int nume1 = 0, denom1 = 0;
	int nume2 = 0, denom2 = 0;
	int digits;
	cin >> nume1 >> denom1 >> nume2 >> denom2 >> digits;
	Fraction f1(nume1,denom1), f2(nume2,denom2);
	f1.output(digits,f2);
	
	system("pause");
	return EXIT_SUCCESS;
}

/*
Example Outputs:
1 3 1 5 7
1 3 0.333333 Not same
Press any key to continue . . .

1 5 1 5 8
1 5 0.2 Is same
Press any key to continue . . .

1 9 1 8 5
1 9 0.11111 Not same
Press any key to continue . . .
*/

