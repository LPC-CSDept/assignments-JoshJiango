#include "Numbers.hpp"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int Numbers::NumofObjects = 0;

int main()
{
  Numbers& n1 = *new Numbers(1, 2);
  Numbers& n2 = *new Numbers(2, 10);
  
}

void printNumbers(Numbers n) 
{
 
}