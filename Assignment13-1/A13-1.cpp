#include "Students.hpp"
#include <iostream>

using namespace std;

int main()
{
  Student s1;
  s1.setSid(10001);
  s1.setSname("John");

  for (int i=0; i<3; i++)
  {
    s1.setScore(i,90);
  }

  cout << "Student Information \n";
  cout << "ID: " << s1.getSid() << endl;
  cout << "Name: " << s1.getSname() << endl;
  cout << "score 1; " << s1.getScores(0) << endl;
  cout << "score 2: " << s1.getScores(1) << endl;
  cout << "score 3: " << s1.getScores(2) << endl;
}