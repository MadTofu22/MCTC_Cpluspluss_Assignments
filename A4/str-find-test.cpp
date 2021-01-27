/*	Program:
	Author: Tom Stutler
	Last Date Modified:

	The intent of this program
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userEmail;

	cout << "Enter email address: ";
	getline(cin, userEmail);

	cout << "find t - first = " << userEmail.find('t') << " and last = " << userEmail.rfind('t') << endl;
}
