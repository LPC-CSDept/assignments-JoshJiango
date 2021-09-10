#include <iostream>

using namespace std;

int binarySearch(int[], int, int);
//1st paramenter: integar array
//2nd paramenter: size of the array N
//3rd paramenter: target value
//return value and type: the index of the array if the target is in the arry. -1 if not found

int main() 
{
  const int N=10;
  int numbers[N] = {10, 25, 30, 35, 40, 45, 55, 60, 65, 70};
  int index;
  int first = 0;
  int last = N-1;
  int mid = (first + last)/2;
  int target=35;

  //cout <<"Pleae enter the # you want to search: " << endl;
  //cin >> target;

  index = binarySearch(numbers, N, target);
  if (index == -1)
  {
    cout << "Not found" << endl;
  }
  else
  {
    cout << "Found at index: " << index << endl;
  }
}

int binarySearch(int numbers[], int N, int target)
{
  int first = 0;
  int last = N-1;
  int mid = (first + last)/2;

  while(first <= last)
  {
    mid = (first + last)/2;
    if(numbers[mid]==target)
    {
      cout << "Found at index: " << mid << endl;
    }
    else if(numbers[mid] < target)
    {
      first = mid +1;
    }
    else if(numbers[mid] > target)
    {
      last = mid - 1;
    }
  }
  return -1;
}