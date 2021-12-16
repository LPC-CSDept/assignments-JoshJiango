// All errors reports are submited into the final exame on Canvas, all testing and error screen shots are submited into Github, Please reivew there for detailed information
#include"Course.hpp"
#include<iostream>
#include<fstream>

using namespace std;

const int NUM_COURSES = 10;

void makeCourses(Course courses[]);
void printCourses(Course courses[]);
void sortCoursesByIdAsc(Course courses[]);
int binarySearch(Course courses[], int target);
//Extra Points
int recursiveBinarySearch(Course courses[], int target, int first, int last);

int main()
{
  Course courses[NUM_COURSES];
  makeCourses(courses);
  printCourses(courses);
  cout << endl;

  cout << "Sorted:" << endl;
  sortCoursesByIdAsc(courses);
  printCourses(courses);
  cout << endl;

  int target, result;

  cout << "Binary Search:" << endl;
  cout << "Please Enter The 3 Digit Course Number: ";
  cin >> target;
  if (target >= 100 && target <= 109)
  {
    result = binarySearch(courses, target);
    courses[result].printCourse();
  }
  else
  {
    cout << "Invaild Input Please Run The Progarm Again" << endl;
  }

  //Extra Points
  cout << endl;
  cout << "Recursive Binary Search:" << endl;
  cout << "Please Enter the 3 Digit Course Number: ";
  cin >> target;
  if (target >= 100 && target <= 109)
  {
    result = recursiveBinarySearch(courses, target, 0, NUM_COURSES);
    courses[result].printCourse();
  }
  else
  {
    cout << "Invaild Input for Recursive Search Please Run The Progarm Again" << endl;
  }
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

//Extra Points 
int recursiveBinarySearch(Course courses[], int target, int first, int last) 
{
  int mid, ret;

  if(first > last)
  {
    return -1;
  }
  mid=(first + last) / 2;
  if(courses[mid].getId() == target)
  {
    return mid;
  }
  if(courses[mid].getId() > target)
  {
    ret=recursiveBinarySearch(courses, target, first, mid-1);
  }
  else
  {
    ret=recursiveBinarySearch(courses, target, mid+1, last);
  }
  return ret;
}