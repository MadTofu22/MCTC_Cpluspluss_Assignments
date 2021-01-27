/*  Program: Recursive Fibonacci Finder
    Author: Tom Stutler
    Last Date Modified: 2/12/15

    The intent of this program is to repeatedly prompt the user to enter a positive integer, n,
    then utilize a recursive function to find the nth term of the Fibonacci sequence.
*/

#include <iostream>
using namespace std;

int fibonacci (int nParam);
//This purpose of this function is to recursively calculate the nth term of the Fibonacci sequence.

int main()
{
    //Declare variables.
    int n, fibTerm;

    //Display program start statement.
    cout << "Fibonacci number generator\n";

    //Loop to repeat finding terms until the user enters 0.
    do
    {
        //Prompt user for n and store to variable.
        cout << "Which one do you want (0 to exit)? ";
        cin >> n;

        //If/else branch to check user input and act accordingly.
        if (n > 0) {
            //Display the result.
            cout << "Fibonacci term #"
                 << n
                 << " is "
                 << fibonacci(n)
                 << endl;
        } else if (n < 0) {
            //Display error statement.
            cout << "Please enter a positive integer.\n";
        } else {
            //Display end of program statement.
            cout << "Thanks for using the Fibonacci number generator!\n";
        }
    } while (n != 0);
}

int fibonacci(int nParam)
{
    int term;

    if (nParam == 1) {
        return 0;
    } else if (nParam == 2) {
        return 1;
    } else {
        term = fibonacci(nParam-1) + fibonacci(nParam-2);
        return term;
    }
}
