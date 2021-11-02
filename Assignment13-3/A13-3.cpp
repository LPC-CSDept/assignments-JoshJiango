#include "student.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void sortStudent(Student *s);
void printStudent(Student &s);


int main()
{
	ifstream ifs;
	const int N = 10;
	string sname;
	int idnum, month, day;
	DOB date;
	Student s[10];

	ifs.open("studentsDOB.txt");
	if (ifs.fail())
	{
		cerr << " File noe open\n";
		exit(0);
	}
	int i = 0;
	while (ifs >> sname >> idnum >> month >> day)
	{
		date.setDOB(month, day);
		s[i].setSname(sname);
		s[i].setID(idnum);
		s[i].setDOB(date);
		i++;
	}

  sortStudent(s);

	for (int i = 0; i < N; i++)
	{
		printStudent(s[i]);
	}
}

//need to sort the DOB before print
void sortStudent(Student *s)
{
  for (int i=0; i<10; i++)
  {
    for (int j=0; j<10-1; j++)
    {
      if(s[j].getDOB().getMonth() > s[j+1].getDOB().getMonth())
      {
        swap(*(s+j), *(s+j+1));
      }
      else if (s[j].getDOB().getMonth() == s[j+1].getDOB().getMonth() && s[j].getDOB().getDay() > s[j+1].getDOB().getDay())
      {
        swap(*(s+j), *(s+j+1));
      }
    }
  }
}

void printStudent(Student &s)
{
	DOB date;
	cout << "Student Name: " << s.getSname() << endl;
	cout << "Student ID: " << s.getID() << endl;
	date = s.getDOB();
	date.printDate();
}