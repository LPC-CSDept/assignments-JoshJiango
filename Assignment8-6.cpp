#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int 	MAX_LEN = 20;
const int 	NUM_SCORES = 3;
struct Students 
{
	int 	sid;
	char 	sname[MAX_LEN];
	double scores[NUM_SCORES];
};

void printStudents(Students [], int);
void makeStudents(Students [], int);
void sortStudents(Students [], int );
int binarySearch(Students [], int , int );

int main()
{
	const int N = 10;
  int target;
	Students s[N];

	makeStudents(s, N); // To read the student information from the file
	printStudents(s, N); 


	// 1) Sort by ID
	sortStudents(s, N);
	printStudents(s, N); 
	// 2) Search the certain student information by the ID (or any other fields)
	// binary search
  cout << "Please enter the 8 digit ID of the student you want to reivew: " << endl;
  cin >> target;

	//int target = 10006677;
  if(target >= 10001111 || target <= 10009999)
  {
	  int result = binarySearch(s, N, target);
	  if (result)
	  {
		  cout << "The student information: \n";
		  cout << s[result].sid << "\t" << s[result].sname << "\t";
      for(int i=0; i<NUM_SCORES; i++)
      {
			  cout <<  s[result].scores[i] << "\t";
      }
		cout << endl;
	  }
  }
  else
  {
   cout << "The ID you entered is invalid please try again." << endl;
  }
}

void sortStudents(Students s[], int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N-1; j++)
		{
			if (s[j].sid > s[j+1].sid)
      {	
			  // if ( strcmp(s[j].sname, s[j+1].sname) > 0 )	
				swap(s[j], s[j+1]);
      }
		}
	}
}

void makeStudents(Students s[], int N)
{
	ifstream ifs;
	ifs.open("students2.txt");

	if ( ifs.fail())
  {
		cout << "Sorry the file can not be found\n";
		exit(0);
	}

	for(int i=0;i<N;i++)
	{
		ifs >> s[i].sid >> s[i].sname;
		for(int j=0;j<NUM_SCORES; j++)
    {
			ifs >> s[i].scores[j];
    }
	}
}

void printStudents(Students s[], int N)
{
	for(int i=0;i<N;i++)
	{
		cout << s[i].sid << "\t" << s[i].sname << "\t";
		for(int j=0; j<NUM_SCORES; j++)
    {
			cout <<  s[i].scores[j] << "\t";
    }
		cout << endl;
	}
	cout << "==== End of Information === \n\n";
}

int binarySearch(Students array[], int N, int target)
{
    int first, last, mid;
    int cmp = 0;

    first = 0;
    last = N-1;
    while ( first <= last) 
    {
        mid = (first + last) / 2;
        if ( array[mid].sid == target)
        {
          return mid;
        }
        if ( array[mid].sid > target)
        {
          last = mid - 1;
        }
        else 
        {
          first = mid + 1;
        }
    }
    return -1;
}