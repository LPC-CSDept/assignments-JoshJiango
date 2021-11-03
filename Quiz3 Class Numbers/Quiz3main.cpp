#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Numbers.hpp"

using namespace std;

int findMax(Numbers[], int);
void deDup(Numbers &, Numbers &);

int main()
{

  const int N = 5;
  srand(time(0));
  Numbers numberset[] = {Numbers(1, 5), Numbers(2, 5), Numbers(3, 10), Numbers(4, 5), Numbers(5, 7)};

  for (int i = 0; i < N; i++)
  {
    cout << "Number Set: ";

    numberset[i].printAll();
  }

  int id = findMax(numberset, N);

  cout << "The set ID that has max difference is " << id << "\t";

  cout << "The diff is " << numberset[id].getMax() - numberset[id].getMin() << endl;
  

  deDup(numberset[2], numberset[3]);

  cout << "ID 3 - ID 4\n ";

  numberset[2].printAll();


  deDup(numberset[0], numberset[1]);

  cout << "ID 1 - ID 2\n ";

  numberset[0].printAll();
}

int findMax(Numbers numberset[], int size)
{
  int id = -1;
  int max = 0;
  for(int i=0; i < size; i++)
  {
    int diff = numberset[i].getMax()-numberset[i].getMin();
    //cout << i << " " << diff << endl;
    if (diff > max)
    {
      max=diff;
      id=i;
    }
  }
  return id;
}

void deDup(Numbers &numberset1, Numbers &numberset2)
{
  for(int i=0; i<numberset2.getSize(); i++)
  {
    numberset1.deleteElm(numberset2.getElm(i));
  }
}