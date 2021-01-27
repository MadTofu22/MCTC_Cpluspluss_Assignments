/*  Program: Area and Perimeter Calc
    Author: Tom Stutler
    Last Date Modified: 2/17/15

    The intent of this program is to prompt the user for a shape (circle, rectangle, or triangle), then prompt the user for
    the appropriate dimensions and calculate then display the area and perimeter to the user. The program must use overloaded functions
    to get the dimensions and calculate the area and perimeter.
*/

#include <iostream>
#include <cmath>
using namespace std;

//Define global variables.
const float PI = 3.141592654;

//Define function prototype.
void getdim (float& radius);
void getdim (float& length, float& width);
void getdim (float& a, float& b, float& c);
/// This function prompts the user for the dimensions of a circle, rectangle, or triangle and returns them to main().

float area (float rParam);
float area (float lParam, float wParam);
float area (float aParam, float bParam, float cParam);
/// This function calculates the area of a circle, rectangle, or triangle and returns it to main().

float perimeter (float rParam);
float perimeter (float lParam, float wParam);
float perimeter (float aParam, float bParam, float cParam);
/// This function calculates the perimeter of a circle, rectangle, or triangle and returns it to main().

int main()
{
    //Declare variables.
    float radius, length, width, a, b, c;
    int userSelec;
    bool repeat = true;

    //Loop to repeat until the user selects exit.
    do {
        //Prompt the user to select a shape and store to a variable.
        cout << "AREA/PERIMETER CALCULATOR\n"
             << "Select a shape:\n"
             << "Circle (1) Rectangle (2) Triangle (3) Exit (4)\n"
             << "Enter selection => ";
        cin >> userSelec;

        //Switch branch to calculate and display the area and perimeter of the selected shape.
        //Or terminates the loop and ends the program if the user selects to exit.
        switch (userSelec)
        {
        default:
            cout << "Please enter a valid input.\n\n";
            break;

        case 1:
            getdim(radius);
            cout << "Circle area = "
                 << area(radius)
                 << " and perimeter = "
                 << perimeter(radius)
                 << "\n\n";
            break;

        case 2:
            getdim(length, width);
            cout << "Rectangle area = "
                 << area(length, width)
                 << " and perimeter = "
                 << perimeter(length, width)
                 << "\n\n";
            break;

        case 3:
            getdim(a, b, c);
            cout << "Triangle area = "
                 << area(a, b, c)
                 << " and perimeter = "
                 << perimeter(a, b, c)
                 << "\n\n";
            break;

        case 4:
            cout << "Bye...\n";
            repeat = false;
        }
    } while (repeat == true);
}

void getdim (float& radius)
{
    cout << "Enter circle radius: ";
    cin >> radius;
}
void getdim (float& length, float& width)
{
    cout << "Enter rectangle length: ";
    cin >> length;
    cout << "Enter rectangle width: ";
    cin >> width;
}
void getdim (float& a, float& b, float& c)
{
    cout << "Enter 1st side of triangle: ";
    cin >> a;
    cout << "Enter 2nd side of triangle: ";
    cin >> b;
    cout << "Enter 3rd side of triangle: ";
    cin >> c;
}

float area (float rParam)
{
    return PI*(rParam*rParam);
}
float area (float lParam, float wParam)
{
    return lParam*wParam;
}
float area (float aParam, float bParam, float cParam)
{
    float s = (aParam+bParam+cParam)/2;
    return sqrt(s*(s-aParam)*(s-bParam)*(s-cParam));
}

float perimeter (float rParam)
{
    return 2*PI*rParam;
}
float perimeter (float lParam, float wParam)
{
    return 2*lParam + 2* wParam;
}
float perimeter (float aParam, float bParam, float cParam)
{
    return aParam+bParam+cParam;
}
