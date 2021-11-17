#include "Rect.hpp"
#include "Square.hpp"
#include <iostream>

using namespace std;

Rect::Rect(){ }

void Rect::setWidth(double rw)
{
  width = rw;
}
void Rect::setHeight(double h)
{
  height = h;
}
double Rect::getWidth(void) const
{
  return width;
}
double Rect::getHeight(void) const
{
  return height;
}
double Rect::getArea(void) const
{
  return width*height;
}
Rect Rect::makeRectanglewithSquare(Square s)
{
  Rect r; 
  r.setWidth(s.width);
  r.setHeight(s.width);
  return r;
}