#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

const int MAX_LEN=20;
const int NUM_SCORES = 3;

struct Students
{
  int sid;
  char sname[MAX_LEN];
  double scores[NUM_SCORES];
};

Students *makeStudents(int);
void printtofile(Students *);

int main()
{
  const int N=10;
  Students *ptr=nullptr;
  ptr = makeStudents(N);
  cout << endl;
  printtofile(ptr);
}

Students *makeStudents(int N)
{
  Students *ptr = new Students [N];

  ifstream ifs;

  ifs.open("students2.txt");
  if(ifs.fail())
  {
    cerr << "File open error\n";
    exit(0);
  }
  for(int i=0; i<N; i++)
  {
    ifs >> (ptr+i)->sid >> (ptr+i)->sname;
    for(int j=0; j<NUM_SCORES; j++)
    {
      ifs >> (ptr+i)->scores[j];
    }
  }
  return ptr;
}

void printtofile(Students *ptr)
{
  ofstream ofs("students2.bin", ios::binary);

  if(ofs.fail())
  {
    cerr << "File open error\n";
    exit(0);
  }

  ofs.write((char *)ptr, sizeof(Students) * 10);
  ofs.close();
}
