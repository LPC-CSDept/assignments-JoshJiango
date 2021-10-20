#include<iostream>
#include<fstream>

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
void sortprintStudents(Students * const, int);

int main()
{
  ifstream input_file("students2.bin", ios::binary);
  Students *ptr = new Students[10];
  input_file.read((char*)ptr, sizeof(Students)*10);  

  const int N=10;
  cout << endl;
  sortprintStudents(ptr, N);
}

void sortprintStudents(Students * const ptr, int N)
{
  double sum = 0;

	for(int i=0; i<N; i++)
	{
    sum = (ptr+i)->scores[0] + (ptr+i)->scores[1] + (ptr+i)->scores[2];
    double avg = sum/3;

    if (avg > 85 )
    {	
      cout << (ptr+i)->sid << "\t" << (ptr+i)->sname << "\t";
      for(int j=0; j<NUM_SCORES; j++)
      {
        cout << (ptr+i)->scores[j] << "\t";
      }
      cout << endl;
    } 
	}
  cout << "======== End of the Record ======== \n\n";
}