#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Students
{
  int id;
  char sname[15];
  double score1, score2;
  double sum;
  double avg;
};

void findstudents(struct Students*);

int main() 
{
  ifstream ifs;
  ofstream ofs;

  Students s[10];
  ifs.open("students.txt");
  ofs.open("students.bin");

  for(int i=1; i<=10; i++)
  {
    ifs >> s[i].id;
    ifs >> s[i].sname;
    ifs >> s[i].score1;
    ifs >> s[i].score2;
    s[i].sum = s[i].score1 + s[i].score2;
    s[i].avg = s[i].sum / 2;
  }

  for(int i=1; i<=10; i++)
  {
    cout << s[i].id << "\t";
    cout << s[i].sname << "\t";
    cout << s[i].score1 << " " << s[i].score2 << "\t";
    cout << s[i].sum << " " << s[i].avg << endl;
  }
  
  for(int i=1; i<=10; i++)
  {
    ofs.write( (char *)&s[i], sizeof(s[i]));
  } 

  ifs.open("students.bin");

  ifs.read((char *)&s, sizeof(s));

  cout << "\n" << endl;

  for (int i=1; i<=10; i++)
  {
    cout << "ID: " << s[i].id << "\t";
    cout << "Name: " << s[i].sname << "\t";
    cout << "Scroe1: " << s[i].score1 << "\t";
    cout << "Score2: " << s[i].score2 << "\t";
    cout << "Sum: " << s[i].sum << "\t";
    cout << "Avg: " << s[i].avg << "\n";
  }

  findstudents(s);
}

void findstudents(struct Students*s)
{
 
  int input;

  cout <<"\nPlease Enter the 5 Digits Student ID You Wish to Find OR press #key ZERO and enter to quit." << endl;
  cin >> input;

  if(input == 0)
  {
    cout <<"Thank you for using the program, good bye!" <<endl;
  }

  else if (input < 0)
  {
    cout <<"Sorry, you have entered an invalid input, program terminated." << endl;
  }
   
  else
  {
   for(int i=1; i<=10; i++)
    {
      if(input == s[i].id)
      {
         cout << "Student Found:" << "\n";
         cout << "ID: " << s[i].id << "\t";
         cout << "Name: " << s[i].sname << "\t";
         cout << "Scroe1: " << s[i].score1 << "\t";
         cout << "Score2: " << s[i].score2 << "\t";
         cout << "Sum: " << s[i].sum << "\t";
         cout << "Avg: " << s[i].avg << "\n";
      }
    }
  }
}