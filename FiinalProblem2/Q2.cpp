#include "Course.hpp"
#include<iostream>
#include<fstream>

using namespace std;

const int NUM_COURSES = 10;

void makeCourses(Course courses[]);
void printCourses(Course courses[]);

int main()
{
  Course courses[NUM_COURSES];
  makeCourses(courses);
  printCourses(courses);
  cout << endl;

}

//Copy From Final Problem 1
void makeCourses(Course courses[]) 
{
  ifstream ifs;

  ifs.open("courses.txt");
  if(ifs.fail())
  {
    cerr << "File open error\n";
    exit(0);
  }
  for(int i=0; i<NUM_COURSES; i++)
  {
    int id;
    string name;
    int credit;
    ifs >> id >> name >> credit;
    courses[i].setId(id);
    courses[i].setName(name);
    courses[i].setCredit(credit);
  }
  ifs.close();
}

//Copy From Final Problem 1
void printCourses(Course courses[])
{
  for(int i=0; i<NUM_COURSES; i++)
  {
    courses[i].printCourse();
  } 
}