#include "student.hpp"
#include <iostream>

using namespace std;

DOB::DOB() : month(1),day(1){}

DOB::DOB(int m,int d) : month(m),day(d){}

int DOB :: getMonth() const 
{ 
	return month;
}

int DOB :: getDay() const 
{ 
	return day;
}

void DOB :: printDate()const 
{
  cout << "DOB: " << month << "\t" << day << endl;
}

void DOB :: setDOB(int m , int d ) 
{
	month = m;
	day = d;
} 

void DOB :: setMonth( int m ) 
{
  month = m;
}

void DOB :: setDay(int d) 
{
  day = d;
}

Student::Student(): sname(), sid(0), dob() {}

Student::Student(string s, int id, DOB d) // : sname(s), sid(id), dob(d) {}
{
  sname = s;
  sid = id;
  dob = d;
}

void Student::setDOB(DOB d)
{
	dob = d;	
}

int Student::getID() const
{
  return sid;
}

string Student::getSname() const
{
  return sname;
}

DOB Student::getDOB() const
{
  return dob;
}

void Student::setSname(string name)
{
  sname = name;
}

void Student::setID(int id)
{
  sid = id;
}