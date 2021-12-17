#include <iostream>

using namespace std; 

void printArray(int array[], int N);
void qsort(int [], int, int);
int partition(int [], int, int);

int main()
{
	const int N = 7;
	int num[] = {1, 8, 5, 9, 4, 3, 7};

	printArray(num, N);
	qsort(num, 0, N - 1);
	printArray(num, N);
}

void qsort(int num[], int first, int last)
{
	int pivot_idx;
  int N=7;

	if ( first >= last)
		return;
	pivot_idx = partition(num, first, last);
  //print to check for # of calls
  cout << first << "\t" << pivot_idx << "\t" << last << endl;
  printArray(num, N);
  cout << "Qsort1 ("<<first<<"," <<last<<")" << first << " " << pivot_idx-1<<endl;
	qsort(num, first, pivot_idx -1); 
  printArray(num, N);
  cout << "Qsort2 ("<<first<<"," <<last<<")" << pivot_idx+1<<" "<<last<<endl;
	qsort(num, pivot_idx +1, last); 
}

int partition(int num[], int first, int last)
{
	int pivot = num[last];
	int i = -1;
	for (int j = 0; j < last; j++)
	{
		if (num[j] < pivot)
    {
			swap(num[++i], num[j]);
    }
	}
	swap(num[i + 1], num[last]);

	return i + 1;
}

void printArray(int array[], int N)
{
  for(int i=0; i<N; i++)
  {
      cout << array[i]  << "\t" ; 
  }
	cout << endl;
}