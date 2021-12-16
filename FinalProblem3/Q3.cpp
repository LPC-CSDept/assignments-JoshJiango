// All errors reports are submited into the final exame on Canvas, all testing and error screen shots are submited into Github, Please reivew there for detailed information
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

  cout << "Comparing Workers with Higher Rate 1st Group: " << endl;
  ProductWorker jiang1 = ProductWorker(11111, "Josh", "10/10/2021", 1, 19.2);
  jiang1.printWorker();
  ProductWorker jiang2 = ProductWorker(11112, "Zack", "10/11/2021", 1, 16.2);
  jiang2.printWorker();
  ProductWorker higherPaidWorker;
  if (jiang1 > jiang2) 
  {
    higherPaidWorker = jiang1;
  } 
  else 
  {
    higherPaidWorker = jiang2;
  }
  cout << "Person With Higher Pay Rate: " << endl;
  higherPaidWorker.printWorker();

  cout << endl;

  // More overload > testing code (copy from the code above)
  cout << "Comparing Workers with Higher Rate 2nd Group: " << endl;
  ProductWorker jiang3 = ProductWorker(11111, "Josh", "10/10/2021", 1, 16.2);
  jiang1.printWorker();
  ProductWorker jiang4 = ProductWorker(11112, "Zack", "10/11/2021", 1, 19.2);
  jiang2.printWorker();
  ProductWorker higherPaidWorker2;
  if (jiang3 > jiang4) 
  {
    higherPaidWorker2 = jiang3;
  } 
  else 
  {
    higherPaidWorker2 = jiang4;
  }
  cout << "Person With Higher Pay Rate: " << endl;
  higherPaidWorker.printWorker();
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