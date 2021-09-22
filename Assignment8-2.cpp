#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void makeArray(int [], int);
void printArray(int [], int);
int linearSearch(int [], int , int );
int binarySearch(int [], int , int );

int main()
{
	const int TRY = 10000;
	const int N = 64;
	int array[N];
	int target;
	int total_linear = 0;

	srand(time(0)); // set the seed number to random function
	makeArray(array, N);
	printArray(array, N);

	for(int i=0; i<TRY; i++){
		target = array[rand() % 64];
		total_linear += linearSearch(array, N, target);
	}
	cout << "The average comparison number " << total_linear / TRY << endl;

	// Sort array

	// call binarySearch TRY times



}

int linearSearch(int array[], int N, int target)
{
    for(int i=0; i<N; i++)
        if ( array[i] == target)
            return i+1;
            
    return N;
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

int binarySearch(int array[], int N, int target)
{
    int first, last, mid;
    int cmp = 0;

    first = 0;
    last = N-1;
    while ( first <= last) 
    {
		cmp += 1;
        mid = (first + last) / 2;
        if ( array[mid] == target)
            return cmp;
        if ( array[mid] > target)
            last = mid - 1;
        else 
            first = mid + 1;
    }
    return cmp;
}