#ifndef NUMBERS_H
#define NUMBERS_H
#include <vector>

using namespace std;

class Numbers
{
  private:
	  int ID;
    vector<int> numbers;

  public:
    Numbers();
    Numbers(int ID, int rnum);
	  int getID() const;
    int getSize() const;
    int getElm(int i) const;
    int getMax() const;
    int getMin() const;
    int getSum() const;
    void deleteElm(int d);
    void addElm(int a);
    void printAll( ) const;
};

#endif