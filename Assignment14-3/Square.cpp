#include "Square.hpp"
#include "Rect.hpp"
#include <iostream>

using namespace std;

Square::Square(){ }

void Square::setWidth(double w)
{
  width = w;
}

int Square::getWidth(void) const
{
  return width;
}

int Square::getArea(void) const
{
  return width*width;
}