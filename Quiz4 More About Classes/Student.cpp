#include "Student.hpp"
#include <string>

using namespace std;

Student::Student() {}
Student::Student(int ID, string sname, char grade, double scores) 
{
  this->ID = ID;
  this->sname = sname;
  this->grade = grade;
  this->scores = scores;
}

int Student::getID(void)
{
  return ID;
}
string Student::getSName(void)
{
  return sname;
}
char Student::getGrade(void)
{
  return grade;
}
double Student::getScores(void)
{
  return scores;
}

void Student::setID(int ID)
{
  this->ID = ID;
}
void Student::setSName(string sname)
{
  this->sname = sname;
}
void Student::setGrade(char grade)
{
  this->grade = grade;
}
void Student::setScores(double scores)
{
  this->scores = scores;
}