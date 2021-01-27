#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   ratnum x,y,res;
   char resp, oper;
   do
   {
        cin >> x;
        cout << "Enter an operation (+, -, *, /): ";
        cin >> oper;
        cin >> y;
        switch (oper)
        {
            case '+':
                 res = x + y;
                 break;
            case '-':
                 res = x - y;
                 break;
            case '*':
                 res = x * y;
                 break;
            case '/':
                 res = x / y;
                 break;
            default:
                 cout << "Invalid operator - try again\n";
                 break;
        }
        cout << x;
        cout << " " << oper << " ";
        cout << y;
        cout << " = ";
        cout << res;
        cout << "\nEnter another pair of rational numbers? (y or n): ";
        cin >> resp;
   } while (resp == 'y');
   return 0;
}

