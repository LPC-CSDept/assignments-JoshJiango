#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
using namespace std;

class Student
{
    private:
        int sid;
        string sname;
        double score[3];

    public:
        int getSid() const;
        string getSname() const;
        double getScores(int) const;
        double getAvg() const;
        void setSid(int);
        void setSname(string);
        void setScore(int,int);
} ;

#endif