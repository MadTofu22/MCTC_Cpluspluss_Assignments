/*  Program: A1P2
    Author: Tom Stutler
    Last Date Modified: 1/21/15

    The intent of this program is to prompt the user for a positive integer, n, then calculate the nth term of the fibonacci sequence.

    PRECONDITION: User must enter a positive integer.
*/

#include <iostream>
using namespace std;

//Prototype function to calculate Fibonacci term.
int calculate_Term(int termParameter);

int main()
{
    //Declare variables.
    int result, userTerm;
    char repeat;

    //Loop to check whether the user wants to find a second term.
    do
    {
        //
        do
        {
            cout << "Enter n>0: ";
            cin >> userTerm;

            result = calculate_Term(userTerm);

            cout << "Fibonacci number " << userTerm << " = " << result << endl;
        } while (userTerm <= 0);

        cout << "Would you like to continue (y or n)? ";
        cin >> repeat;

    } while ((repeat == 'y') || (repeat == 'Y'));
}

int calculate_Term (int termParameter)
{
    int value, currentTerm, firstTerm=0, secondTerm=1;

    for (currentTerm=2; currentTerm < termParameter; currentTerm++)
    {
        value = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = value;
    }

    return value;
}
