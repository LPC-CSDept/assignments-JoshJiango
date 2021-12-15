#include "Course.hpp"
#include<iostream>
#include<fstream>

using namespace std;

const int NUM_COURSES = 10;

void makeCourses(Course courses[]);
void printCourses(Course courses[]);
void qsort(Course[], int first, int last);
int partition(Course courses[], int first, int last);

int main()
{
  Course courses[NUM_COURSES];
  makeCourses(courses);
  cout << "Original Course List From txt File" << endl;
  printCourses(courses);
  cout << endl;

  cout << "Result With Quick Sorted: " << endl;
  qsort(courses, 0, NUM_COURSES);
  printCourses(courses);
}

//Copy From Final Problem 1
void makeCourses(Course courses[]) 
{
  ifstream ifs;

  ifs.open("courses.txt");
  if(ifs.fail())
  {
    cerr << "File Open Error\n";
    exit(0);
  }
  for(int i=0; i<NUM_COURSES; i++)
  {
    int id;
    string name;
    int credit;
    ifs >> id >> name >> credit;
    courses[i].setId(id);
    courses[i].setName(name);
    courses[i].setCredit(credit);
  }
  ifs.close();
}

//Copy From Final Problem 1
void printCourses(Course courses[])
{
  for(int i=0; i<NUM_COURSES; i++)
  {
    courses[i].printCourse();
  } 
}

void qsort(Course courses[], int first, int last)
{
  int pivot_idx;

	if ( first >= last)
  {
		return;
  }
  pivot_idx = partition(courses, first, last);
  //print to check for # of calls, copyright to Jiang
  //cout << first << "\t" << pivot_idx << "\t" << last << endl;
	qsort(courses, first, pivot_idx -1); 
	qsort(courses, pivot_idx +1, last);
}

int partition(Course courses[], int first, int last)
{
  int pivot = courses[last].getId();
	int i = -1;
  
  for (int j = 0; j < last; j++)
	{
		if (courses[j].getId() < pivot)
    {
			swap(courses[++i], courses[j]);
    }
	}
	swap(courses[i + 1], courses[last]);

	return i + 1;
}