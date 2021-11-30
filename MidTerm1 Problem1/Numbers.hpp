#ifndef 	NUMBERS_H
#define 	NUMBERS_H
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

class Numbers
{
  private:
		int ID;
    vector<int> values;
    static int NumofObjects;

  public:
    // Consturctor
    Numbers() 
    {
      // Increment total object count
      NumofObjects += 1;
    }
    Numbers(int i, int n) 
    {
      // ID
      ID = i;
      
      // Generate numbers
      for(int i=0; i<n; i++)
      {
        values.push_back(rand() % 100);
      }

      // Increment total object count
      NumofObjects += 1;
    }


};

#endif