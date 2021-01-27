/*  Program: Quadratic Formula Solver
    Author: Tom Stutler
    Last date modified: 2/9/15

    The intent of this program is to prompt the user for A, B, and C then calculate the solution x using the quadratic formula.
*/

#include <iostream>
#include <cmath>

using namespace std;

void calc_solution (float aParam, float bParam, float cParam, float& solution1, float& solution2, float& discriminate);
//The purpose of this function is to take the user input a, b, and c and calculate the discriminate.
//If the discriminate is < 0, assign -b/2a to solution 1 and 2.
//If the discriminate == assign 0 to solution 1 and 2.
//If the discriminate is > 0 assign (-b+sqrt(b^2-4ac)/2a) to solution 1 and (-b-sqrt(b^2-4ac)/2a)

int main()
{
    float a, b, c, solution1, solution2, discriminate;

    do
    {
        cout << "Enter a: ";
        cin >> a;

        if (a == 0) {

            cout << "a cannot be 0 - reenter.\n";
        } else {

            cout << "Enter b: ";
            cin >> b;
            cout << "Enter c: ";
            cin >> c;

            calc_solution(a, b, c, solution1, solution2, discriminate);

            if (discriminate < 0) {

                discriminate = (sqrt(-1*discriminate)/(2*a));

                cout << "There are two complex solutions: "
                     << solution1 << "+" << discriminate << "i and "
                     << solution2 << "-" << discriminate << "i\n";
            } else if (discriminate == 0) {

                cout << "There is one real solution: "
                     << solution1 << endl;
            } else {

                cout << "There are two real solutions: "
                     << solution1
                     << " and "
                     << solution2 << endl;
            }
        }
    } while (a == 0);
}

void calc_solution (float aParam, float bParam, float cParam, float& solution1, float& solution2, float& discriminate)
{
    discriminate = ((bParam*bParam)-4*aParam*cParam);

    if (discriminate > 0) {
        solution1 = (-1*bParam + sqrt(discriminate))/2*aParam;
        solution2 = (-1*bParam - sqrt(discriminate))/2*aParam;
    } else {
        solution1 = ((-1*bParam)/(2*aParam));
        solution2 = ((-1*bParam)/(2*aParam));
    }
}
