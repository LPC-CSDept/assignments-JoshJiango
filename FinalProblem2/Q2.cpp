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
  cout << "Original Course List From Reading txt File: " << endl;
  printCourses(courses);
  cout << endl;

  cout << "Result With Quick Sorted: " << endl;
  qsort(courses, 0, NUM_COURSES-1);
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

/*
//Print the Trace For The Tree Diagram 
void qsort(Course courses[], int first, int last)
{
  cout << "start: " << first << " " << last << endl;
  int pivot_idx;

	if ( first >= last)
  {
		cout <<"return" <<endl;
    return;
  }

	pivot_idx = partition(courses, first, last);
  //print to check for # of calls
  cout << first << "\t" << pivot_idx << "\t" << last << endl;
  //cout <<courses[0].getId();
  printCourses(courses);
  cout << "cqsort1 ("<<first<<"," <<last<<")" << first << " " << pivot_idx-1<<endl;
	qsort(courses, first, pivot_idx -1); 

  printCourses(courses);
  cout << "cqsort2 ("<<first<<"," <<last<<")" << pivot_idx+1<<" "<<last<<endl;
	qsort(courses, pivot_idx +1, last); 
}
*/