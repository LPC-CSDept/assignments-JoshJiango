#include"Course.hpp"
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