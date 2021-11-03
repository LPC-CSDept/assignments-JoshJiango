#include "Numbers.hpp"
#include <iostream>

using namespace std;

int getID() const;
{
  return ID;
}

int getSize() const;
{
  return numbers.size(); // return the vector size
}

int getElm(int i) const;
{
  return numbers.at(i); // return the i_th element;
}

int getMax() const ;
{
  return //the max mavlue in vectors
}

int getMin() const;
{
  return the min value in vectors
}
int getSum() const;
{
  return the sum of vector values
}

void deleteElm(int d) ;
{
  //delete all the elements that is the same as the value d from the vector.
}

void addElm(int a) ;
{
  //Add the value as a last element to the vector. This value could be duplicated to others.
}

void printAll( ) const;
{
  //Print all elements in a vector.
}