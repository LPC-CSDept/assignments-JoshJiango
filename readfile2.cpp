#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};

int main()
{
  ifstream ifs;
  Student s;

  ifs.open("students.bin");

  ifs.read((char *)&s, sizeof(s));

  cout << "ID: " << s.id << "\t";
  cout << "Name: " << s.sname << "\t";
  cout << "Scroe1: " << s.score[0] << "\t";
  cout << "Score2: " << s.score[1] << "\t";
  cout << "Sum: " << s.sum << "\t";
  cout << "Avg: " << s.avg << "\n";
}