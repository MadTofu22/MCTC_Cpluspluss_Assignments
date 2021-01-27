/*  Program: A1P3
    Author: Tom Stutler
    Last Date Modified: 1/21/15

    The intent of this program is to prompt the user for two fractions and a mathematical operator (+,-,*,/),
    then calculate the new fraction using a switch statement, and display the result to the user. Once complete prompt
    the user if they want to calculate another fraction.
*/

#include <iostream>
using namespace std;

int main()
{
    //Declare variables.
    int numer1, numer2, numerFinal, denom1, denom2, denomFinal;
    char slash, userOperator, repeat;

    //Loop to check whether the user wants to calculate a new fraction.
    do
    {
        //Prompt user for first fraction and assign to variables.
        cout << "Enter the first fraction: ";
        cin >> numer1 >> slash >> denom1;

        //Prompt user for the operator they want to use.
        cout << "Enter operation: ";
        cin >> userOperator;

        //Prompt user for second fraction and assign t variables.
        cout << "Enter the second fraction: ";
        cin >> numer2 >> slash >> denom2;

        //Switch branch to calculate the user defined operation on the user entered fractions.
        switch (userOperator)
        {
            //Default case for invalid input. Warns the user to enter correct input and restarts the program.
            default:
                cout << "Please enter a valid operator (+,-,*,/).\n";
                break;

            //Add's two fractions and displays the output.
            case '+':
                numerFinal = (numer1*denom2) + (numer2*denom1);
                denomFinal = denom1*denom2;
                cout << "Sum = " << numerFinal << slash << denomFinal << endl;
                break;

            //Subtract's two fractions and displays the output.
            case '-':
                numerFinal = (numer1*denom2) - (numer2*denom1);
                denomFinal = denom1*denom2;
                cout << "Difference = " << numerFinal << slash << denomFinal << endl;
                break;

            //Multiplies two fractions and displays the output.
            case '*':
                numerFinal = numer1*numer2;
                denomFinal = denom1*denom2;
                cout << "Product = " << numerFinal << slash << denomFinal << endl;
                break;

            //Divides two fractions and displays the output.
            case '/':
                numerFinal = numer1*denom2;
                denomFinal = denom1*numer2;
                cout << "Quotient = " << numerFinal << slash << denomFinal << endl;
                break;
        }

        //Prompts the user if they want to continue the program or end.
        cout << "Continue (y or n)? ";
        cin >> repeat;

    } while (repeat == 'y');
}
