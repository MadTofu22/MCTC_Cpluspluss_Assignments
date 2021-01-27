/*	Program:
	Author: Tom Stutler
	Last Date Modified: 4/9/15

	The intent of this program is to prompt the user for an email
	address and check then return to the user whether the email
	address is valid and if not what the error is.
*/

#include <iostream>

using namespace std;

int NUM_OF_TESTS=4;

bool test0 (string emailParam);
///Takes in an email address and returns true
///if the string has a space in it.

bool test1 (string emailParam);
///Takes in an email address and returns true
///if the string has more than one @ symbol in it.

bool test2 (string emailParam);
///Takes in an email address and returns true
///if the string begins with an @ symbol.

bool test3 (string emailParam);
///Takes in an email address and returns true
///if the string contains a dot char, '.', without
///a non-dot/non-@ on either side of the dot.

void displayerror(int errorParam);
///Takes in an error code, the number of the
///test that failed, and outputs the error
///message to the user.

int main()
{
	string userEmail;
	bool testArray[NUM_OF_TESTS];
	char repeat;
	int testPass=0;

	do
	{
		cout << "Enter email address: ";
		getline(cin, userEmail);

		cout << "You entered: " << userEmail << endl;

		testArray[0] = test0(userEmail);
		testArray[1] = test1(userEmail);
		testArray[2] = test2(userEmail);
		testArray[3] = test3(userEmail);

		for (int i=0; i<NUM_OF_TESTS; i++) {
			if (testArray[i]==true) {
				displayerror(i);
			} else {
				testPass++;
			}
		}
		if (testPass==4) {
			cout << "Address is valid!\n";
		}

		do
		{
			cout << "Enter another (y or n)? ";
			cin >> repeat;
			repeat = toupper(repeat);

			if (repeat!='Y' && repeat!='N') {
				cout << "Invalid input!\n";
			}
		} while (repeat!='Y' && repeat!='N');

		cin.ignore(80, '\n');

	} while (repeat=='Y');
}

bool test0 (string emailParam)
{
	if (emailParam[emailParam.find(' ')]==' ') {
		return true;
	} else {
		return false;
	}
}

bool test1 (string emailParam)
{
	int symbolIndex, symbolCount=0;

	symbolIndex = emailParam.find('@');

	do
	{
		if (emailParam[symbolIndex]=='@') {
			symbolCount++;
		}

		symbolIndex = emailParam.find('@', symbolIndex+1);
	} while (symbolIndex<emailParam.length());

	if (symbolCount==1) {
		return false;
	} else {
		return true;
	}
}

bool test2 (string emailParam)
{
	if (emailParam[0]=='@') {
		return true;
	} else {
		return false;
	}
}

bool test3 (string emailParam)
{
	int dotIndex;
	bool invalidDot;

	dotIndex = emailParam.find('.');

	do
	{
		if (isalpha(toupper(emailParam[dotIndex-1]))==true
			&& isalpha(toupper(emailParam[dotIndex+1]))==true) {
			invalidDot = false;
		} else {
			return true;
		}

		dotIndex = emailParam.find('.', dotIndex+1);
	} while (dotIndex<emailParam.length());

	return invalidDot;
}

void displayerror (int errorParam)
{
	switch (errorParam)
	{
	case 0:
		cout << "Not valid - contains a blank\n";
		break;

	case 1:
		cout << "Not valid - not exactly one '@'\n";
		break;

	case 2:
		cout << "Not valid - '@' is first character\n";
		break;

	case 3:
		cout << "Not valid - a dot is first or last, "
			 <<	"or preceeded or followed by '@' or' ' or '.'\n";
		break;
	}
}
