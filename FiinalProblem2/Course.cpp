//Codes Are Copied Over From Final Problem 1 cpp, Because They Share The Same hpp And cpp
#include "Course.hpp"
#include<iostream>
#include<string>

using namespace std;

// Constructor
Course::Course() { }
Course::Course(int id, string name, int credit)
{
  this->id = id;
  this->name = name;
  this->credit = credit;
}

// Getter
int Course::getId(void)
{
  return id;
}
string Course::getName(void)
{
  return name;
}
int Course::getCredit(void)
{
  return credit;
}

// Setter  
void Course::setId(int id)
{
  this->id = id;
}
void Course::setName(string name)
{
  this->name = name;
}
void Course::setCredit(int credit)
{
  this->credit = credit;
}

// Helper
void Course::printCourse()
{
  cout << id << "\t" << name << "\t" << credit << endl;
}