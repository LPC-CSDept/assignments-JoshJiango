#include"Course.hpp"
#include<iostream>
#include<fstream>

using namespace std;

const int NUM_COURSES = 10;

void makeCourses(Course courses[]);
void printCourses(Course courses[]);
void sortCoursesByIdAsc(Course courses[]);
int binarySearch(Course courses[], int target);

int main()
{
  Course courses[NUM_COURSES];
  makeCourses(courses);
  printCourses(courses);
  cout << endl;

  cout << "Sorted:" << endl;
  sortCoursesByIdAsc(courses);
  printCourses(courses);
}

void makeCourses(Course courses[]) 
{
  ifstream ifs;

  ifs.open("courses.txt");
  if(ifs.fail())
  {
    cerr << "File open error\n";
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

void printCourses(Course courses[])
{
  for(int i=0; i<NUM_COURSES; i++)
  {
    courses[i].printCourse();
  } 
}

void sortCoursesByIdAsc(Course courses[])
{
	for(int i=0; i<NUM_COURSES; i++)
	{
		for(int j=0; j<NUM_COURSES-1; j++)
		{
			if (courses[j].getId() > courses[j+1].getId())
      {	
			  swap(courses[j], courses[j+1]);
      }
		}
	}
}

int binarySearch(Course courses[], int target)
{
  int first, last, mid;

  first = 0;
  last = NUM_COURSES-1;

  while (first <= last) 
  {
    mid = (first + last) / 2;
    // cout << first << " " << mid << " " << last << endl;
    if (target == courses[mid].getCredit())
    {
      return mid;
    }
    if (target < courses[mid].getCredit())
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