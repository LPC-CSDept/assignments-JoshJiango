#include "ProductWorker.hpp"
#include <iostream>
#include <fstream>

using namespace std;

const int NUM_WORKERS = 10;

void makeWorkers(ProductWorker workers[]);
void printWorkers(ProductWorker workers[]);

int main()
{
  ProductWorker workers[NUM_WORKERS];
  makeWorkers(workers);
  printWorkers(workers);
  cout << endl;
}

void makeWorkers(ProductWorker workers[]) 
{
  ifstream ifs;

  ifs.open("worker.txt");
  if(ifs.fail())
  {
    cerr << "File open error\n";
    exit(0);
  }
  for(int i=0; i<NUM_WORKERS; i++)
  {
    string name;
    int id;
    string hireDate;
    int shift;
    double rate;
    ifs >> name >> id >> hireDate >> shift >> rate;
    workers[i].setName(name);
    workers[i].setId(id);
    workers[i].setHireDate(hireDate);
    workers[i].setShift(shift);
    workers[i].setPayRate(rate);
  }
  ifs.close();
}

void printWorkers(ProductWorker workers[])
{
  for(int i=0; i<NUM_WORKERS; i++)
  {
    workers[i].printWorker();
  } 
}