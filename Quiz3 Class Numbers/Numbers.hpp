#ifndef NUMBERS_H
#define NUMBERS_H

using namespace std;

class Numbers
{
  private:
	  int ID = -1;
    vector<int> numbers[0];

  public:
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