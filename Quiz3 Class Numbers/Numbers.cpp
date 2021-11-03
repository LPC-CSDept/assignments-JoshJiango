#include "Numbers.hpp"
#include <iostream>
#include <vector>

using namespace std;

Numbers::Numbers(): ID(-1), numbers() {}
Numbers::Numbers(int id, int size)
{
  ID=id;
  for(int i=0; i<size; i++)
  {
    numbers.push_back(rand()%99);
  }
}

int Numbers::getID() const
{
  return ID;
}

int Numbers::getSize() const
{
  return numbers.size(); // return the vector size
}

int Numbers::getElm(int i) const
{
  return numbers.at(i); // return the i_th element;
}

int Numbers::getMax() const 
{
  int max = numbers[0];
  for(int i=0; i<numbers.size(); i++)
  {
    if(max < numbers[i])
    {
      max = numbers[i];
    }
  }
  return max;//the max mavlue in vectors
}

int Numbers::getMin() const
{
  int min = numbers[0];
  for(int i=0; i<numbers.size(); i++)
  {
    if(min > numbers[i])
    {
      min = numbers[i];
    }
  }
  return min; //the min value in vectors
}

int Numbers::getSum() const
{
  int sum=0;
  for(int i=0; i<numbers.size(); i++)
  {
    sum=numbers[i];
    sum=sum+sum;
  }

  return sum; // the sum of vector values
}

void Numbers::deleteElm(int d) 
{
  //delete all the elements that is the same as the value d from the vector.
  vector<int>::iterator iter;
  for(iter=numbers.begin(); iter < numbers.end() ; iter++)
	{
		if ( *iter == d)
			numbers.erase(iter--);
      //cout << "Removing Number: " << d << endl;
	}
}

void Numbers::addElm(int a)
{
  //Add the value as a last element to the vector. This value could be duplicated to others.
  numbers.push_back(a);
}

void Numbers::printAll( ) const
{
  //Print all elements in a vector.
  cout << "ID: " << ID << "\t";
  for(int i=0; i < numbers.size(); i++)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;
}