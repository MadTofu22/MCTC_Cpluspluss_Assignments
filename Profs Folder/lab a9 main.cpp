#include <iostream>
using namespace std;

int main()
{
   rectangle r;
   box b;
   r.get();
   r.show();
   cout << "Area = " << r.area() << endl;
   b.get();
   b.show();
   cout << "Volume = " << b.volume() << endl;
   cout << "Surface area = " << b.surfacearea() << endl;
   return 0;
}
