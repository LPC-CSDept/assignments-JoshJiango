#include "ProductWorker.hpp"
#include "Employee.hpp"
#include<iostream>
#include<string>

using namespace std;

// Constructor
ProductWorker::ProductWorker() { }
ProductWorker::ProductWorker(int id, string name, string hireDate, int shift, double payRate)
{
  this->setId(id);
  this->setName(name);
  this->setHireDate(hireDate);
  this->shift = shift;
  this->payRate = payRate;
}