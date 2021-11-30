#include "Numbers.hpp"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int Numbers::NumofObjects = 0;

int main()
{
  Numbers& n1 = *new Numbers(1, 4);
  Numbers& n2 = *new Numbers(2, 10);
  
  cout << "n1: ";
  printNumbers(n1);
  cout << "Sum of n1: " << n1.getSummation() << endl;
  cout << "n2: ";
  printNumbers(n2);
  cout << "Sum of n2: " << n2.getSummation() << endl;

  cout << "Sum of n1 > Sum of n2 (1 = true, 0 = false): " << (n1 > n2) << endl;
  cout << "Sum of n2 > Sum of n1 (1 = true, 0 = false): " << (n2 > n1) << endl;

  cout << endl;

  Numbers& n3 = *new Numbers(1, 10);
  Numbers& n4 = *new Numbers(2, 4);

  cout << "n3: ";
  printNumbers(n3);
  cout << "Sum of n3: " << n3.getSummation() << endl;
  cout << "n4: ";
  printNumbers(n4);
  cout << "Sum of n4: " << n4.getSummation() << endl;

  cout << "Sum of n3 > Sum of n4 (1 = true, 0 = false): " << (n3 > n4) << endl;
  cout << "Sum of n4 > Sum of n3 (1 = true, 0 = false): " << (n4 > n3) << endl;
}

void printNumbers(Numbers n) 
{
  for(int i = 0; i < n.values.size(); i++) 
  {
    cout << n.values[i] << " ";
  }
  cout << endl;
}