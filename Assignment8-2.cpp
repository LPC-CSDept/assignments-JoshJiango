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
	
	// you should return the comparison number. In for-loop, you have to have a code to count the comparisons.
	
	
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
		
		// return the comparison number
		
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
	
	// return the comparison number.
	
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

//This program creates an array with 64 elements and is filled with random numbers generated by the rand() function. It also randomly generates a target number that we are interested in to search and compare to the numbers in the 64 elements array. % 64 is used to limit the range so the search will be within the array size. The program then sums up the result of each successful attempt of locating the target in the array and divided by the number of iteration (TRY=1000 in this case) to get an average attempt of locating the target number during TRY times. We created 2 types of search functions, the linear search and binary search. In linear search, the order of number in the array is random unsorted, however, during binary search, the array is sorted in an increasing order before the search is executed. After many attempts of running the program the conclusion that I got is that linear search is a bit faster compared to binary search on average attempt (in TRY times) to locate the target number.
