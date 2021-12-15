//Codes Are Copied Over From Final Problem 1 cpp, Because They Share The Same hpp And cpp
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
    Course(int, string, int);

    int getId();
    string getName();
    int getCredit();

    void setId(int);
    void setName(string);
    void setCredit(int);

    void printCourse();
};

#endif