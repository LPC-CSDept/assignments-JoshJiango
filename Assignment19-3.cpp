// recursive version of binarySearch
//
// Pros and Cons of recursion vs iteration
//
// Pros: It take less time to run the program compared to iteration. 
//       It is more clear and cleaner in code and takes less time to write the code.
//       When using the tree diagram, it is easyer to track and traverse as recursive version.
// Cons:
//       Recursion uses more memory space to run compared to iteration version.
//       Recursion runs possibly slower than its iteration version.
       
#include <iostream>

using namespace std;

int binarySearch(int[], int, int, int);

int main()
{
  const int N = 10;
  int array[N] = {10, 15, 20, 25, 30 , 35, 40, 45, 50, 55}, target, foundindex;

  cout << endl;
  cout << "Enter the target number you want to find in this array: ";
  cin >> target;

  foundindex = binarySearch(array, 0, N - 1, target);
  if(foundindex == -1)
  {
    cout << "The target value was not found \n";
  }
  else
  {
    cout << "The target value " << "(" << target << ")" << " is found at the index position " << "(" << foundindex << ")" << endl << endl;
  }
}

int binarySearch(int array[], int first, int last, int target)
{
  int mid, ret;

  if(first > last)
  {
    return -1;
  }
  mid=(first + last) / 2;
  if(array[mid] == target)
  {
    return mid;
  }
  if(array[mid] > target)
  {
    ret=binarySearch(array, first, mid -1, target);
  }
  else
  {
    ret=binarySearch(array, mid+1, last, target);
  }
  return ret;
}