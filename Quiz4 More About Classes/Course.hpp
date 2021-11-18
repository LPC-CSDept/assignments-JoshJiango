#ifndef 	COURSE_H
#define 	COURSE_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Student;

class Course
{
	private:
		string cname;
    int credits;
    string semester;
    vector<Student> student;
    static int NUM_COURSES;

  public:
    Course();
    Course(string, int, string, vector<Student>);

    string getCName(void);
    int getCredits(void);
    string getSemester(void);
    vector<Student> getStudent(void);
    
    void setCName(string);
    void setCredits(int);
    void setSemester(string);
    void setStudent(vector<Student>);

    void addStudent(Student &s);
    void setCourse(string, int, string, vector<Student>);
    void printCourse(void);
    
    static int getNumCourses();
    
    friend ifstream &operator>>(ifstream &, Course &);
    friend ostream &operator<<(ostream &, Course &);
};

#endif