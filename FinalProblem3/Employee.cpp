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

// Setter  
void Employee::setId(int id)
{
  this->id = id;
}
void Employee::setName(string name)
{
  this->name = name;
}
void Employee::setHireDate(string credit)
{
  this->hireDate = hireDate;
}
void Employee::printWorkers()
{
  cout << name << "\t" << id << "\t" << hireDate << endl;
}