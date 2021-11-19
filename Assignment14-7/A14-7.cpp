#include "Student.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ostream &operator>>(istream &is, Student &s)
{

	DOB dob;
	Course c;
	vector<Course> clist;
	
	int m, d,y, count, credit;
	string name, cname, semester;
	double score;
	char grade;

	is >> name >> m >> d >> y ;
	dob.setDOB(m,d,y);
	is >> count;
	for(int i =0; i< count; i++)
	{
		is >> cname >> credit >> grade >> score >> semester ;
		c.setCourse(cname, credit, grade, score, semester);
		clist.push_back(c);

	}
	s.setStudent(name, dob, clist);
}

ostream &operator<<(ostream &os, Student &s)
{
	DOB dob;
	vector<Course> cslist;

	os << s.getSname() << "\t\t";
	dob = s.getDOB();
	os << "DOB: " << dob.getMonth() << "/" << dob.getDay() << "/" << dob.getYear() << endl;
	cslist = s.getCourse();
	os << "\t\t\t Course Name \tCredit \t Grade \t Score \t Semester \n";
	for (int i = 0; i < cslist.size(); i++)
	{
		os << "\t\t\t " << cslist[i].getCname() << "\t\t";
		os << cslist[i].getCredit() << "\t ";
		os << cslist[i].getGrade() << "\t ";
		os << cslist[i].getScore() << "\t";
		os << cslist[i].getSemester() << "\n";
	}
	return os;
}


int main()
{
	const int N = 5;
	ifstream ifs;

	ofstream ofs;
	Student 	s[N];

	ifs.open("studentcourse.txt");
	ofs.open("Studentwritten.txt");
	for(int i=0;i<N; i++)
	{
		ifs >> s[i];
		ofs << s[i] ; 
	}
}