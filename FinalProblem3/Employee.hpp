#ifndef 	EMPLOYEE_H
#define 	EMPLOYEE_H
#include <string>

using namespace std;

class Employee
{
  private:
    int id;
    string name;
    string hireDate;

  public:
    Employee();
    Employee();
    int getId();
    string getName();
    string getHireDate();
    void setId();
    void setName();
    void setHireDate();
    void printWorkers();
};

#endif