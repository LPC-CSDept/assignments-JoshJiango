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
    ProductWorker(int, string, string, int, double);

    int getShift();
    double getPayRate();

    void setShift(int);
    void setPayRate(double);

    void printWorker();

    friend bool operator> (const ProductWorker&, const ProductWorker& that);

    friend ProductWorker findHighestHourlyRate(ProductWorker worker []);
};

#endif