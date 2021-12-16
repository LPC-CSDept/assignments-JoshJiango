#include "Employee.hpp"
#include<iostream>
#include<string>

using namespace std;

// Constructor
Employee::Employee() { }
Employee::Employee(int id, string name, string hireDate)
{
  this->id = id;
  this->name = name;
  this->hireDate = hireDate;
}

// Getter
int Employee::getId(void)
{
  return id;
}
string Employee::getName(void)
{
  return name;
}
string Employee::getHireDate(void)
{
  return hireDate;
}