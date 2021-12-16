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

// Getter
int ProductWorker::getShift(void)
{
  return shift;
}
double ProductWorker::getPayRate(void)
{
  return payRate;
}

// Setter  
void ProductWorker::setShift(int shift)
{
  this->shift = shift;
}
void ProductWorker::setPayRate(double payRate)
{
  this->payRate = payRate;
}