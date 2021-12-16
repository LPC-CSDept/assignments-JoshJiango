#ifndef PRODUCT_WORKER_H
#define PRODUCT_WORKER_H
#include "Employee.hpp"
#include <string>

using namespace std;

class ProductWorker : public Employee
{
  private:
    int shift;
    double payRate;

  public:
    ProductWorker();
    ProductWorker();

    int getShift();
    double getPayRate();

    void setShift();
    void setPayRate(d);

    void printWorker();
};

#endif