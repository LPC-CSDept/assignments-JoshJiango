#ifndef COURSE_H
#define COURSE_H
#include<string>

using namespace std;

class Course
{
  private:
    int id;
    string name;
    int credit;

  public:
    Course();
    Course();
    int getId();
    string getName();
    int getCredit();
    void setId();
    void setName();
    void setCredit();
    void printCourse();
};

#endif