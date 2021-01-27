/*  Program: A1P4
    Author: Tom Stutler
    Last Date Modified: 1/21/15

    The intent of this program is for the user to enter an integer, n, then approximate the square root of n within a precision of 0.00001.

    PRECONDITION: The user must enter a positive integer for n and their first approximation.
*/

#include <iostream>
using namespace std;

//Prototype function to calculate the approximation of the square root.
double calc_Approx(double nParam, double approxParam);

int main ()
{
    //Declare variables.
    int n;
    double approx, answer;

    //Set precision for displaying the answer.
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);

    //Prompt user for a positive integer to approximate the square root of and assign it to a variable.
    cout << "Enter n: ";
    cin >> n;

    //Prompt user for their initial approximation of the square root and assign it to a variable.
    cout << "Enter first approximation: ";
    cin >> approx;

    //Use calc_Approx to evaluate the approximation of n, then assign to answer.
    answer = calc_Approx(n, approx);

    //Display the result to the user.
    cout << "The square root of " << n << " = " << answer << endl;
}

double calc_Approx(double nParam, double approxParam)
{
    //Declare variables.
    double answer;

    //Initiate the calculation with the user input approximation.
    answer = ((nParam/approxParam)+approxParam)/2;

    //Loop to calculate the approximate square root within a precision of 0.00001.
    do
    {
        approxParam = answer;
        answer = ((nParam/approxParam)+approxParam)/2;
    } while ((answer-approxParam < -0.00001) || (answer-approxParam > 0.00001));

    //Return value to main.
    return answer;
}
