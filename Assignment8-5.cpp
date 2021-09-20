#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int>, int);
void printVector(vector<string>, int);

int main() 
{
  const int N=10;
  int choice;
 
  vector<int> ID = {10001, 10003, 10005, 10007, 10009, 10002, 10004, 10006, 10008, 10010};
  vector<string> Names = {"Mary", "Rhona", "Lorita", "Maxim", "Mike", "Kathy", "Elaine", "Smith", "Chen", "Nacy"};

  printVector(ID, 10);
  printVector(Names, 10);

  cout << "Please choose the sorting method: \n" << "Enter '1' for sorting by IDs \n" << "Enter '2' for sorting by Names" << endl;
  cin >> choice;

  if(choice==1)
  {
    for(int i=0; i<ID.size(); i++)
    {
      for(int j=0; j<ID.size()-1; j++)
      {
        if(ID[j] > ID[j+1])
        {
          swap(ID[j], ID[j+1]);
          swap(Names[j], Names[j+1]);
        }
      }
    }
    printVector(ID, 10);
    printVector(Names, 10);
  }
  if(choice==2)
  {
    for(int i=0; i<Names.size(); i++)
    {
      for(int j=0; j<Names.size()-1; j++)
      {
        if(Names[j] > Names[j+1])
        {
          swap(Names[j], Names[j+1]);
          swap(ID[j], ID[j+1]);
        }
      }
    }
    printVector(ID, 10);
    printVector(Names, 10);
  }
  else 
    cout << "Invaild input detetcted, Please run the program again with the vaild input" << endl;  
}

void printVector(vector<int> ID, int N)
{
  for(int i =0; i<N; i++)
  {
    cout << ID[i] << "\t";
  }
  cout <<endl;
}

void printVector(vector<string> Names, int N)
{
  for(int i =0; i<N; i++)
  {
    cout << Names[i] << "\t";
  }
  cout <<endl;
}