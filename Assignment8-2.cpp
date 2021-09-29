#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void makeArray(int [], int);
void printArray(int [], int);
void bubbleSort(int [], int);
int linearSearch(int [], int , int );
int binarySearch(int [], int , int );

int main()
{
	const int TRY = 1000;
	const int N = 64;
	int array[N];
	int target;
	int total_linear = 0;
  int total_binary = 0;

	srand(time(0)); // set the seed number to random function
	makeArray(array, N);
	printArray(array, N);

	for(int i=0; i<TRY; i++)
  {
		target = array[rand() % 64];
		total_linear += linearSearch(array, N, target);
	}
	cout << "The average comparison number with linearSearch is: " << total_linear / TRY << endl << endl;

	// Sort array
  bubbleSort(array, N);
  printArray(array, N);

	// call binarySearch TRY times
  for(int i=0; i<TRY; i++)
  {
    target = array[rand() % 64];
    //cout << target << endl;
		total_binary += binarySearch(array, N, target);
  }
  cout << "The average comparison number with binarySearch is: " << total_binary / TRY << endl;

}

int linearSearch(int array[], int N, int target)
{
    for(int i=0; i<N; i++)
    {
        if ( array[i] == target)
        {
          return i+1;
        }
    }
    return N;
}

int binarySearch(int array[], int N, int target)
{
    int first, last, mid;
    //int cmp = 0;

    first = 0;
    last = N-1;
    while ( first <= last) 
    {
		//cmp += 1;
        mid = (first + last) / 2;
        if (array[mid] == target)
        {
          //return cmp;
          return mid;
        }
        if (array[mid] > target)
        {
          last = mid - 1;
        }
        else 
        {
          first = mid + 1;
        }
    }
    //return cmp;
    return -1;
}

void makeArray(int array[], int N)
{
	for(int i=0; i<N; i++)
		array[i] = rand() % 100 +1 ;  // random nubers between 1 to 100

}

void printArray(int array[], int N)
{
    for(int i=0; i<N; i++)
    {
        cout << array[i]  << "\t" ; 
        if (i % 8 == 7 ) cout << endl;
    }
}

void bubbleSort(int array[], int N)
{
  for(int i=0; i<N-1; i++)
  {
    for(int j=0; j<N-i-1; j++)
    {
      if(array[j]>array[j+1])
      {
        swap(array[j], array[j+1]);
      }
    }
  }
}