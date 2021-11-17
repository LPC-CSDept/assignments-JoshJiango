#include "Rect.hpp"
#include "Square.hpp"
#include <iostream>

using namespace std;

const int N=2;

int main()
{
  Square s;
  s.setWidth(N);

  Rect r;
  r = r.makeRectanglewithSquare(s);

  cout << "The Area of the Square is: " << s.getArea() << endl;

  cout << "The Area of the Rectangle with width from Square is: " << r.getArea() << endl;
}