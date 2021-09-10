#include <iostream>

using namespace std;

int main() 
{
  const int N=10;
  int numbers[N] = {10, 25, 30, 35, 40, 45, 55, 60, 65, 70};
  int first = 0;
  int last = N-1;
  int mid = (first + last)/2;
  int target=35;

  //cout <<"Pleae enter the # you want to search: " << endl;
  //cin >> target;

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
}