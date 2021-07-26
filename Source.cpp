/* This program converts
ZIP Code to ASCII bar code format
which can be usefule for shipping labels etc.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void barCode(int digit);
int zipTotal(int zip);
void digitCheck(int number);





int main() {

	//Header
	cout << "======================================================= \n";
	cout << "Zip Code to Bar Code\n ";
	cout << "Long Beach City College\n ";
	cout << "Author: Douglas Lopez \n";
	cout << "Oct. 28, 2018 \n";
	cout << "======================================================= \n";



	// Variable Declaration
	int zip = 0;
	int zipsum = 0;
	int d5, d4, d3, d2, d1 = 0;
	

	//Inputs instructions for user
	cout << "Please enter a 5 digit Zip Code: ";
	cin >> zip;

	//Digit Seperation
	zipsum = zip;
	d5 = zip % 10;  //takes zip code and modulo 10
	zip /= 10;     // divides zip by 10 and assigns 4 digits to zip
	d4 = zip % 10;   // takes 4 digit zip and modulo 10
	zip /= 10;       //divides zip by 10 and assigns 3 digits to zip and process repeats till 1 digit is left
	d3 = zip % 10;  
	zip /= 10;
	d2 = zip % 10;
	zip /= 10;
	d1 = zip;
	

	cout << "The corresponding barcode for the zip code " << zipsum << " is: " << endl;
	cout << "|";
	barCode(d1);   //Calls Void and uses digit seperation to print out barcode desired
	barCode(d2);
	barCode(d3);
	barCode(d4);
	barCode(d5);
	digitCheck(zipTotal(zipsum)); 
	cout << "|\n\n"; 

	cout << "Thank you for using the Zip Code to Bar Code Program" << endl;
	cout << "Goodbye...!"<<endl;
	cout << "=======================================================" << endl;


	system("Pause"); //would it affect the console output if I add this in the end of the whole program?
	return 0;

}


int zipTotal(int zip)
{
	int sum = 0;
	do
	{
		sum = sum + zip % 10;
		zip = zip / 10;
	} while (zip > 0);
	return sum;
}

void digitCheck(int number)
{
	number %= 10;
	int diffNum = 0;
	if (0 <= number & number <= 10)
		diffNum = 10 - number;

	barCode(diffNum);
}

// Definitions
//Respective barcode for each digit entered
void barCode(int digit)
{
	switch (digit)
	{
	case 0:
		cout << "||:::";
		break;
	case 1:
		cout << ":::||";
		break;
	case 2:
		cout << "::|:|"; 
		break;
	case 3:
		cout << "::||:";
		break;
	case 4:
		cout << ":|::|";
		break;
	case 5:
		cout << ":|:|:";
		break;
	case 6:
		cout << ":||::";
		break;
	case 7:
		cout << "|:::|";
		break;
	case 8:
		cout << "|::|:";
		break;
	case 9:
		cout << "|:|::";
		break;
	default:
		cout << "Please enter a valid zip code"; //Instructions are not met

	}
}


	
	

