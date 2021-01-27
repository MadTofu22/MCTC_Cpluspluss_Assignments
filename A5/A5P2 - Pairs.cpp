/*	Program: A5P2 - Pairs
	Author: Tom Stutler
	Last Date Modified: 5/7/2015

	The intent of this program is to demonstrate knowledge
	of inherited classes in c++.
*/

#include <iostream>
#include <cmath>

using namespace std;

const int SZ=6;

class pairs
{
protected:
    float a, b;

public:
    pairs () : a(0), b(0) {}
    pairs (const pairs& p) : a(p.a), b(p.b) {}

    bool operator ==(pairs& pairsParam)
        {
            if (a==pairsParam.a && b==pairsParam.b) {
                return true;
            } else {
                return false;
            }
        }
    pairs operator +(pairs& pairsParam)
        {
            pairs newPair;
            newPair.a = a+pairsParam.a;
            newPair.b = b+pairsParam.b;
            return newPair;
        }
    pairs operator -(pairs& pairsParam)
        {
            pairs newPair;
            newPair.a = a-pairsParam.a;
            newPair.b = b-pairsParam.b;
            return newPair;
        }
};

class complex : public pairs
{
private:
    char oper;

public:
    complex () : oper('+') {pairs();}
    complex (const pairs& p) : pairs(p) {}

    complex operator *(complex& cParam)
    {
        complex newComplex;
        newComplex.a = (a*cParam.a) - (b*cParam.b);
        newComplex.b = (a*cParam.b) + (b*cParam.a);
        return newComplex;
    }
    complex operator /(complex& cParam)
    {
        complex newComplex;
        newComplex.a = (a*cParam.a + b*cParam.b)/(pow(cParam.a, 2) + pow(cParam.b, 2));
        newComplex.b = (a*cParam.a - b*cParam.b)/(pow(cParam.a, 2) + pow(cParam.b, 2));
        return newComplex;
    }

    friend ostream& operator <<(ostream& output, complex& cParam)
    {
        if (cParam.b>=0) {
            output << cParam.a << cParam.oper << cParam.b << "i";
            return output;
        } else {
            output << cParam.a << cParam.b << "i";
            return output;
        }
    }
    friend istream& operator >>(istream& input, complex& cParam)
    {
        char i;
        input >> cParam.a >> cParam.oper >> cParam.b >> i;
        if (cParam.oper == '-') {
            cParam.b = 0-cParam.b;
        }
        return input;
    }
};

class vect : public pairs
{
public:
    vect () {pairs();}
    vect (const pairs& p) : pairs(p) {}

    float operator *(vect& vParam)
    {
        return (a*vParam.a + b*vParam.b);
    }
    vect operator *(float numParam)
    {
        vect newVect;
        newVect.a = a*numParam;
        newVect.b = b*numParam;
        return newVect;
    }

    friend ostream& operator <<(ostream& output, vect& vParam)
    {
        output << "<" << vParam.a << "," << vParam.b << ">";
        return output;
    }
    friend istream& operator >>(istream& input, vect& vParam)
    {
        char bracket, comma;
        input >> bracket >> vParam.a >> comma >> vParam.b >> bracket;
        return input;
    }
};

int selectset();
void ComplexLand (complex cArry[]);
void VectorLand (vect vArry[]);

int main()
{
    int sel;
    complex cx[SZ];
    vect vx[SZ];

    do {
        cout << "Select an option - (1) Enter Complex Number Land\n";
        cout << "                   (2) Enter Vector Land\n";
        cout << "                   (3) Exit\n";
        cin >> sel;
        if(sel == 1)
            ComplexLand(cx);
        else if(sel == 2)
            VectorLand(vx);
        else if (sel == 3)
            cout << "Bye...\n";
        else
            cout << "Invalid input - try again\n";
    } while (sel != 3);

    char ch; cin >> ch;
return 0;
}

int selectset()
{
	int iset;
	char set;

	do
	{
		cout << "(enter A-F): ";
		cin >> set;
		set = toupper(set);
		iset = set-'A';
		if (iset<0 || iset>5) {
			cout << "Invalid - reenter\n";
		}
	} while (iset<0 || iset>5);

	return iset;
}

void ComplexLand (complex cArry[])
{
    int selMenu, set1, set2, set3;
    char selOper;
    complex temp;

    do
    {
        cout << "Select an option:\n"
             << "\t(1) Enter a complex number\n"
             << "\t(2) Display all complex numbers\n"
             << "\t(3) Perform arithmetic or equality check\n"
             << "\t(4) Exit\n";
        cin >> selMenu;

        switch (selMenu)
        {
        case 1:
            cout << "Enter a complex number in a+bi or a-bi form: ";
            cin >> temp;
            cout << "Where do you want to store this ";
            set1 = selectset();
            cArry[set1] = temp;
            break;
        case 2:
            cout << "A: " << cArry[0]
                 << "\nB: " << cArry[1]
                 << "\nC: " << cArry[2]
                 << "\nD: " << cArry[3]
                 << "\nE: " << cArry[4]
                 << "\nF: " << cArry[5] << endl;
                 break;
        case 3:
            cout << "Enter an operation:   +   -   *   /   =  ";
            cin >> selOper;

            if (selOper=='=') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();

                if (cArry[set1] == cArry[set2]) {
                    cout << cArry[set1] << " does equal " << cArry[set2] << endl;
                } else {
                    cout << cArry[set1] << " does not equal " << cArry[set2] << endl;
                }
            } else if (selOper=='/') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();
                cout << "Enter result location ";
                set3 = selectset();

                cArry[set3] = cArry[set1]/cArry[set2];
            } else if (selOper=='*') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();
                cout << "Enter result location ";
                set3 = selectset();

                cArry[set3] = cArry[set1]*cArry[set2];
            } else if (selOper=='-') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();
                cout << "Enter result location ";
                set3 = selectset();

                cArry[set3] = cArry[set1]-cArry[set2];
            } else if (selOper=='+') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();
                cout << "Enter result location ";
                set3 = selectset();

                cArry[set3] = cArry[set1]+cArry[set2];
            } else {
                cout << "Invalid input.\n";
            }
            break;
        default:
            cout << "Invalid input. Please try again.\n";
            break;

        }
    }while (selMenu != 4);
}

void VectorLand (vect vArry[])
{
    int selMenu, set1, set2, set3;
    float scalar;
    char selOper;
    vect temp;

    do
    {
        cout << "Select an option:\n"
             << "\t(1) Enter a complex number\n"
             << "\t(2) Display all complex numbers\n"
             << "\t(3) Perform arithmetic or equality check\n"
             << "\t(4) Exit\n";
        cin >> selMenu;

        switch (selMenu)
        {
        case 1:
            cout << "Enter a complex number in a+bi or a-bi form: ";
            cin >> temp;
            cout << "Where do you want to store this ";
            set1 = selectset();
            vArry[set1] = temp;
            break;
        case 2:
            cout << "A: " << vArry[0]
                 << "\nB: " << vArry[1]
                 << "\nC: " << vArry[2]
                 << "\nD: " << vArry[3]
                 << "\nE: " << vArry[4]
                 << "\nF: " << vArry[5] << endl;
                 break;
        case 3:
            cout << "Enter an operation:   +   -   .(dot prod)   *(scalar prod)   =  ";
            cin >> selOper;

            if (selOper=='=') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();

                if (vArry[set1] == vArry[set2]) {
                    cout << vArry[set1] << " does equal " << vArry[set2] << endl;
                } else {
                    cout << vArry[set1] << " does not equal " << vArry[set2] << endl;
                }
            } else if (selOper=='.') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();
                cout << "The dot product = " << vArry[set1]*vArry[set2] << endl;
            } else if (selOper=='*') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter scalar: ";
                cin >> scalar;
                cout << "Enter result location ";
                set2 = selectset();
                vArry[set2] = vArry[set1]*scalar;
            } else if (selOper=='-') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();
                cout << "Enter result location ";
                set3 = selectset();

                vArry[set3] = vArry[set1]-vArry[set2];
            } else if (selOper=='+') {
                cout << "Enter first number ";
                set1 = selectset();
                cout << "Enter second number ";
                set2 = selectset();
                cout << "Enter result location ";
                set3 = selectset();

                vArry[set3] = vArry[set1]+vArry[set2];
            } else {
                cout << "Invalid input.\n";
            }
            break;
        default:
            cout << "Invalid input. Please try again.\n";
            break;

        }
    }while (selMenu != 4);
}
