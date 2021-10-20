#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int *fillupArray(int N);
void printArray(int * const ptr, int N);

int main()
{
  const int N=10;
  int *ptr=nullptr;

  ptr = fillupArray(N);
  printArray(ptr, N);
}

int *fillupArray(int N)
{
  int *ptr = new int [N];
  srand(time(nullptr));
  for(int i=0; i<N; i++)
  {
    ptr[i] = rand() % 100;
  }
  return ptr;
}

void printArray(int * const ptr, int N)
{
  for(int i=0; i<N; i++)
  {
    cout << *(ptr+i) << "\t";
  }
  cout << endl;
}