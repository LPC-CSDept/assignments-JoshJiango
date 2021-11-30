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

    // Getter/Setter
    int getID(void) 
    {
      return ID;
    }
    int getSummation() const
    {
      int sum = 0;
      for(int i = 0; i < values.size(); i++) 
      {
        sum += values[i];
      }
      return sum;
    }

    // Overloading
    bool operator>(const Numbers& n2)
    {
      return getSummation() > n2.getSummation();
    }
    
    // Friends
    friend void printNumbers(Numbers);

};

#endif