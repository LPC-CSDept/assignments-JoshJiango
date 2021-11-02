#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>
using namespace std;

class Stack
{
    private:
		  vector<int> pool;

    public:
		  Stack()
		  {
			  pool.reserve(0);
		  }
		  Stack(int s)
		  {
			  pool.reserve(s);
		  }
		  int isEmpty()
		  {
			  return pool.empty();
		  }
		  void clear()
		  {
			  pool.clear();
		  }
		  void push(int el)
		  {
			  pool.push_back(el);
		  }
		  int pop() 
		  {
			  int value = pool.back();
			  pool.pop_back();
			  return value;
		  }
		  int topEl() 
		  {
			  return pool.back();
		  }
		  int getSize()
		  {
			  return pool.size();
		  }
		  void printAll() 
		  {
			  for(int i=0; i<pool.size(); i++)
        {
				  cout << pool[i] << "\t";
        }
			  cout <<endl;
		  }
};

#endif