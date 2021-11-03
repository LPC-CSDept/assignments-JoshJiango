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

  /*
  numberset[0].printAll(); // Class object instance
  numberset[1].printAll(); // Class object instance
  numberset[2].printAll(); // Class object instance
  numberset[3].printAll(); // Class object instance
  numberset[4].printAll(); // Class object instance
  */

  for (int i = 0; i < N; i++)
  {
    cout << "Number Set ID " << numberset[i].getID() << "\t";

    numberset[i].printAll();
  }

  int id = findMax(numberset, N);

  cout << "The set ID that has max difference is " << id << "\t";

  cout << "The diff is " << numberset[id].getMax() - numberset[id].getMin() << endl;
  

  deDup(numberset[2], numberset[3]);

  cout << "ID 3 - ID 4\n ";

  numberset[2].printAll();


  deDup(numberset[0], numberset[1]);

  cout << "ID 1 - ID 2\n";

  numberset[0].printAll();
}