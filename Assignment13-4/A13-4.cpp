#include <iostream>
#include "Stack.hpp"

using namespace std;

int main()
{
  int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  Stack s(10);

  for(int i=0; i<10; i++)
  {
    s.push(numbers[i]);
  }
  s.printAll();

  for(int i=0; i<10; i++)
  {
    numbers[i] = s.pop();
  }

  for(int i=0; i<10; i++)
  {
    cout << numbers[i] << endl;
  }
}
