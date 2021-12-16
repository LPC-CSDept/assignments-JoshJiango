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
    Employee(int, string, string);

    int getId();
    string getName();
    string getHireDate();

    void setId(int id);
    void setName(string name);
    void setHireDate(string credit);

    void printWorkers();
};

#endif