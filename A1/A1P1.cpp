/*  Program: A1P1
    Author: Tom Stutler
    Last Date Modified: 1/13/15

    The intent of this program is to prompt the user for two monetary values,
    using the pound-shilling-pence system, collect the sums, then display the result
    in both the old system and the newer pound-pence system.
*/

#include <iostream>
using namespace std;

int main()
{
    //Declare variables.
    int pound, shill, pence, poundSum, shillSum, penceSum, decPence;
    char dot1, dot2;

    //Prompt user for first set of monetary values, then store them to their respective variables.
    cout << "Enter first old-pound amount: ";
    cin >> poundSum >> dot1 >> shillSum >> dot2 >> penceSum;

    //Prompt user for second set of monetary values, then store them to their respective variables.
    cout << "Enter second old-pound amount: ";
    cin >> pound >> dot1 >> shill >> dot2 >> pence;

    //Total both sets of input.
    poundSum += pound;
    shillSum += shill;
    penceSum += pence;

    //Check if there are more than 12 pence, if so round them up to shillings.
    if (penceSum >= 12)
        shillSum += penceSum/12;
        penceSum = penceSum%12;

    //Check if there are more than 20 shilling
    if (shillSum >= 20)
        poundSum += shillSum/20;
        shillSum = shillSum%20;

    //Convert old pence and shillings into new pence.
    decPence = (penceSum+(shillSum*12))/2.4;

    //Display the results to the user.
    cout << "Old-pound total = " << poundSum << dot1 << shillSum << dot2 << penceSum << endl;
    cout << "Decimal-pound total = " << poundSum << dot2 << decPence << endl;
}
