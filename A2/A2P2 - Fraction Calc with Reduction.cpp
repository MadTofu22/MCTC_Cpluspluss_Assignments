/*  Program: Fraction Calc with Reduction
    Author: Tom Stutler
    Last Date Modified: 2/12/15

    The intent of this program is to prompt the user for two fractions and a mathematical operator (+,-,*,/),
    then calculate the new fraction using a switch statement, and display the result to the user. Once complete prompt
    the user if they want to calculate another fraction. Once calculated, find the greatest common divisor and reduce the fraction.
*/

#include <iostream>
using namespace std;

int gcd (int larger, int smaller);
//The purpose of this function is to take the user input denominators
//and find the greatest common divisor using Euclid's method.


int main()
{
    //Declare variables.
    int numer1, numer2, numerFinal, denom1, denom2, denomFinal, divisor;
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
                numerFinal = (numer1*denom2)+(numer2*denom1);
                denomFinal = denom1*denom2;
                divisor = gcd(numerFinal, denomFinal);
                cout << "Sum = " << numerFinal/divisor << slash << denomFinal/divisor << endl;
                break;

            //Subtract's two fractions and displays the output.
            case '-':
                numerFinal = (numer1*denom2) - (numer2*denom1);
                denomFinal = denom1*denom2;
                divisor = gcd(numerFinal, denomFinal);
                cout << "Difference = " << numerFinal/divisor << slash << denomFinal/divisor << endl;
                break;

            //Multiplies two fractions and displays the output.
            case '*':
                numerFinal = numer1*numer2;
                denomFinal = denom1*denom2;
                divisor = gcd(numerFinal, denomFinal);
                cout << "Product = " << numerFinal/divisor << slash << denomFinal/divisor << endl;
                break;

            //Divides two fractions and displays the output.
            case '/':
                numerFinal = numer1*denom2;
                denomFinal = denom1*numer2;
                divisor = gcd(numerFinal, denomFinal);
                cout << "Quotient = " << numerFinal/divisor << slash << denomFinal/divisor << endl;
                break;
        }

        //Prompts the user if they want to continue the program or end.
        cout << "Continue (y or n)? ";
        cin >> repeat;

    } while (repeat == 'y');
}

int gcd (int larger, int smaller)
{
    int remainder;

    do
    {
        remainder = larger%smaller;
        larger = smaller;
        smaller = remainder;
    } while (remainder != 0);

    return larger;
}
