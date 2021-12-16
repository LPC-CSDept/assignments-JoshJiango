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

  cout << "Find Highest Pay Rate: " << endl;
  ProductWorker highestWorker = findHighestHourlyRate(workers);
  highestWorker.printWorker();
  cout << endl;

  cout << "Comparing Workers with Higher Rate: " << endl;
  ProductWorker* worker1 = new ProductWorker(11111, "Hua", "10/10/2021", 1, 19.2);
  ProductWorker* worker2 = new ProductWorker(11112, "Jiang", "10/11/2021", 1, 16.2);
  ProductWorker* higherPaidWorker;

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

bool operator> (const ProductWorker& p1, const ProductWorker& p2)
{
  // cout << p1.payRate << " " << p2.payRate << endl;
  return p1.payRate > p2.payRate;
}

ProductWorker findHighestHourlyRate(ProductWorker workers[])
{
  ProductWorker highestWorker = workers[0];
  for(int i=1; i<NUM_WORKERS; i++)
  {
    if ( workers[i] > highestWorker)
    {
      highestWorker = workers[i];
    }
  } 
  return highestWorker;
}