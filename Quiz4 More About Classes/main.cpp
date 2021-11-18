#include "Course.hpp"
#include "Student.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

int main() 
{
  int N = 4;
  Course courses[N];
  ifstream ifs;

  // Process original file
  ifs.open("coursestudents.txt");
  if(ifs.fail())
  {
    cerr << "File open error\n";
    exit(0);
  }
  for(int i=0; i<N; i++)
  {
    ifs >> courses[i];
    cout << courses[i] << endl;
  }
  ifs.close();

  // Process additional file
  ifs.open("addstudents.txt");
  if(ifs.fail())
  {
    cerr << "File open error\n";
    exit(0);
  }
  string courseId;
  while (ifs >> courseId)
  {
    cout << "Course ID: " << courseId << endl;
    int courseIndex;
    for(int i = 0; i < Course::getNumCourses(); i++) 
    {
      if (courses[i].getCName() == courseId) 
      {
        courseIndex = i;
      }
    }

    int numStudent;
    ifs >> numStudent;

    for (int i = 0; i < numStudent; i++) 
    {
      int ID;
      string sname;
      char grade; 
      double scores;
      ifs >> ID >> sname >> grade >> scores;
      Student s(ID, sname, grade, scores);
      courses[courseIndex].addStudent(s);
    }
    cout << "Updated Students list for the Course: " << courseId << endl;
    cout << courses[courseIndex] << endl;
  }
  ifs.close();

  // Print final result
  for(int i=0; i<Course::getNumCourses(); i++)
  {
    cout << courses[i] << endl;
  }
} 


// Override Input Stream for Course
ifstream &operator>>(ifstream &ifs, Course &c)
{
  string cname;
  int credits;
  string semester;
  ifs >> cname >> credits >> semester;

  int numStudent;
  ifs >> numStudent;

  vector<Student> students;
  for(int i=0; i<numStudent; i++) 
  {
    int ID;
    string sname;
    char grade; 
    double scores;
    ifs >> ID >> sname >> grade >> scores;
    Student s(ID, sname, grade, scores);
    students.push_back(s);
  }

  c.setCourse(cname, credits, semester, students);
}


// Override Output Stream for Course
ostream &operator<<(ostream &os, Course &c)
{
  os << c.getCName() << "\t" << c.getCredits() << "\t" << c.getSemester() << endl;
  os << "StudentID\tCredit\tGrade\tScore\t" << endl;
  for(int i = 0; i < c.getStudent().size(); i++) 
  {
    os << c.getStudent()[i].getID() << "\t\t" << c.getStudent()[i].getSName() << "\t\t" << c.getStudent()[i].getGrade() << "\t\t" << c.getStudent()[i].getScores() << endl;
  }
  os << "";
}