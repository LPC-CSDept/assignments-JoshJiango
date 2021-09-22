#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void makeArray(int[], int);
void printArray(int [], int);
int binarySearch(int [], int, int);
int linearSearch(int[], int, int);

int main()
{
  const int TRY = 100;
  const int N = 64;
  int array[N];
  int target;
  int total_linear = 0;

  srand(time(0)); //set the seed number to random function
  makeArray(array, N);
  printArray(array, N);

  for(int i=0; i<TRY; i++)
  {
    target = array[rand() % 64];
    total_linear += linearSearch(array, N, target);
  }
  cout << "The average comparison number: " << total_linear / TRY << endl;

  //call any sort array function

  //call binarySearch TRY times
}

int linearSearch(int array[], int N, int target)
{
  for(int i=0; i<N; i++)
  {
    if(array[i] == target)
    {
      return i+1;
    }
  }
  return N;
}

void makeArray(int array[], int N)
{
  for(int i=0; i<N; i++)
  {
    array[i] = rand()%100+1; // random numbers between 1 to 100
  }
}

void printArray(int array[], int N)
{
  for(int i=0; i<N; i++)
  {
    cout << array[i] << "\t";
    if(i % 8 ==7) cout << endl;
  }
}

/*
int binarySearch(int array[], int N, int target)
{
  int first, last, mid;
  int cmp = 0;

  first = 0;
  last = 
}
*/

int binarySearch(int numbers[], int N, int target)
{
  int first = 0, last = N-1;
  
  while(first <= last)
  {
    int mid = (first + last)/2;
    if(numbers[mid] == target)
    {
      return mid;
    }
    if(numbers[mid] < target)
    {
      first = mid +1;
    }
    else
    {
      last = mid - 1;
    }
  }
 return -1;
}