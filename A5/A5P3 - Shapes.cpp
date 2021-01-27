/*	Program: A5P3 - Shapes
	Author: Tom Stutler
	Last Date Modified: 5/7/2015

	The intent of this program is to demonstrate knowledge
	of virtual functions in c++ and practice using inherited
	classes again.
*/

#include <iostream>
#include <cmath>

using namespace std;

const float PI = 3.14159265359;
const int MAX_SHAPES = 20;

class Shape
{
protected:
	float volume, perim, area;

public:
	Shape () : volume(0), perim(0), area(0) {}

	virtual void Display() = 0;
	virtual void GetDimensions() = 0;
	virtual float Perimeter() = 0;
	virtual float Area() = 0;
	virtual float Volume() = 0;
};

class Rectangle : public Shape
{
private:
	float length, width;

public:
	Rectangle () : Shape(), length(0), width(0) {GetDimensions();}

	void Display ()
	{
		cout << "\nShape = Rectangle "
			 << " Length = " << length
			 << " Width  = " << width
			 << endl;
	}
	void GetDimensions ()
	{
		cout << "Input for Rectangle - enter length and width: ";
		cin >> length >> width;
	}
	float Perimeter ()
	{
		perim = 2*length + 2*width;
		cout << "Perimeter = " << perim << endl;
	}
	float Area ()
	{
		area = length*width;
		cout << "Area = " << area << endl;
	}
	float Volume () {}
};

class Circle : public Shape
{
private:
	float r;

public:
	Circle () : Shape(), r(0) {GetDimensions();}

	void Display ()
	{
		cout << "\nShape = Circle  Radius = " << r << endl;
	}
	void GetDimensions ()
	{
		cout << "Input for Circle - enter radius: ";
		cin >> r;
	}
	float Perimeter ()
	{
		perim = 2*PI*r;
		cout << "Perimeter = " << perim << endl;
	}
	float Area ()
	{
		area = PI*pow(r,2);
		cout << "Area = " << area << endl;
	}
	float Volume () {}
};

class Triangle : public Shape
{
private:
	float a, b, c;

public:
	Triangle () : Shape(), a(0), b(0), c(0) {GetDimensions();}

	void Display ()
	{
		cout << "\nShape = Triangle  Side lengths = "
			 << a << " "  << b << " " << c << endl;
	}
	void GetDimensions ()
	{
		cout << "Input for Triangle - enter side 1, side 2, side 3: ";
		cin >> a >> b >> c;
	}
	float Perimeter ()
	{
		perim = a+b+c;
		cout << "Perimeter = " << perim << endl;
	}
	float Area ()
	{
		float p = perim/2.0;
		area = sqrt(p*(p-a)*(p-b)*(p-c));
		cout << "Area = " << area << endl;
	}
	float Volume () {}
};

class Box : public Shape
{
private:
	float l, w, h;

public:
	Box () : Shape(), l(0), w(0), h(0) {GetDimensions();}

	void Display ()
	{
		cout << "\nShape = Box  Length = " << l
			 << " Width = " << w
			 << " Height = " << h << endl;
	}
	void GetDimensions ()
	{
		cout << "Input for Box - enter length, width, and height: ";
		cin >> l >> w >> h;
	}
	float Volume ()
	{
		volume = l*w*h;
		cout << "Volume = " << volume << endl;
	}
	float Area ()
	{
		area = 2*l*w + 2*w*h + 2*l*h;
		cout << "Surface area = " << area << endl;
	}
	float Perimeter () {}
};

class Can : public Shape
{
private:
    float r, h;

public:
	Can () : Shape(), r(0), h(0) {GetDimensions();}

	void Display ()
	{
		cout << "\nShape = Can  Radius = " << r
			 << " Height = " << h << endl;
	}
	void GetDimensions ()
	{
		cout << "Input for Can - enter radius and height: ";
		cin >> r >> h;
	}
	float Volume ()
	{
		volume = PI*pow(r,2)*h;
		cout << "Voume = " << volume;
	}
	float Area ()
	{
		area = 2*PI*pow(r,2) + 2*PI*r*h;
		cout << "Surface area = " << area << endl;
	}
	float Perimeter () {}
};

class Cone : public Shape
{
private:
    float r, h;

public:
	Cone () : Shape(), r(0), h(0) {GetDimensions();}

	void Display ()
	{
		cout << "\nShape = Cone  Radius = " << r
			 << " Height = " << h << endl;
	}
	void GetDimensions ()
	{
		cout << "Input for cone - enter radius and height: ";
		cin >> r >> h;
	}
	float Volume ()
	{
		volume = (PI*pow(r,2)*h)/3;
		cout << "Voume = " << volume << endl;
	}
	float Area ()
	{
		area = PI*pow(r,2) + PI*r*sqrt(pow(h,2)+pow(r,2));
		cout << "Surface area = " << area << endl;
	}
	float Perimeter () {}
};

class Ball : public Shape
{
private:
    float r;

public:
	Ball () : Shape(), r(0) {GetDimensions();}

	void Display ()
	{
		cout << "\nShape = Ball  Radius = " << r << endl;
	}
	void GetDimensions ()
	{
		cout << "Input for ball - enter radius: ";
		cin >> r;
	}
	float Volume ()
	{
		volume = (4*PI*pow(r,3))/3;
		cout << "Voume = " << volume << endl;
	}
	float Area ()
	{
		area = 4*PI*pow(r,2);
		cout << "Surface area = " << area << endl;
	}
	float Perimeter () {}
};

int main()
{
	Shape* pArray[MAX_SHAPES];
	int selShape, numOfShapes=0;
	char repeat;
	Rectangle *rect;
	Circle *circ;
	Triangle *tri;
	Box *bo;
	Can *ca;
	Cone *co;
	Ball *ba;

	do
	{
		cout << "It is time to enter your shape selection and dimensions.\n"
			 << "Enter the number of the shape type:\n"
			 << "   1 - Rectangle\n"
			 << "   2 - Circle\n"
			 << "   3 - Triangle\n"
			 << "   4 - Box\n"
			 << "   5 - Can\n"
			 << "   6 - Cone\n"
			 << "   7 - Ball\n"
			 << "=> ";
		cin >> selShape;

		switch (selShape)
		{
		case 1:
			rect = new Rectangle;
			pArray[numOfShapes] = rect;
			numOfShapes++;
			break;

		case 2:
			circ = new Circle;
			pArray[numOfShapes] = circ;
			numOfShapes++;
			break;

		case 3:
			tri = new Triangle;
			pArray[numOfShapes] = tri;
			numOfShapes++;
			break;

		case 4:
			bo = new Box;
			pArray[numOfShapes] = bo;
			numOfShapes++;
			break;

		case 5:
			ca = new Can;
			pArray[numOfShapes] = ca;
			numOfShapes++;
			break;

		case 6:
			co = new Cone;
			pArray[numOfShapes] = co;
			numOfShapes++;
			break;

		case 7:
			ba = new Ball;
			pArray[numOfShapes] = ba;
			numOfShapes++;
			break;

		default:
			cout << "Invalid - reenter\n";
			break;
		}

		do
		{
			cout << "\nSelect another shape? (y or n): ";
			cin >> repeat;
			repeat = toupper(repeat);

		} while (repeat!='Y' && repeat!='N');

	} while(repeat=='Y' && numOfShapes<MAX_SHAPES);

	if (numOfShapes==MAX_SHAPES) {
		cout << "Max number of shapes reached.\n";
	}

	cout << "Next, a display of your selected shapes, dimensions, and other data\n";
	for (int i=0; i<=numOfShapes; i++) {
		pArray[i]->Display();
		pArray[i]->Area();
		pArray[i]->Perimeter();
		pArray[i]->Volume();
	}

	delete [] pArray;
	delete [] rect;
	delete [] circ;
	delete [] tri;
	delete [] bo;
	delete [] ca;
	delete [] co;
	delete [] ba;

	cout << "\n Thank you, come again!\n";
}
