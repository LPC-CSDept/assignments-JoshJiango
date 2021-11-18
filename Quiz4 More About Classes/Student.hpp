#ifndef 	STUDENT_H
#define 	STUDENT_H
#include <string>

using namespace std;

class Student
{
	private:
		int ID;
    string sname;
    char grade;
    double scores;

  public:
    Student();
    Student(int, string, char, double);

    int getID(void);
    string getSName(void);
    char getGrade(void);
    double getScores(void);
    
    void setID(int);
    void setSName(string);
    void setGrade(char);
    void setScores(double);
};

#endif