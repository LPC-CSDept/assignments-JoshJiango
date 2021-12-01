#ifndef 	MIDTERMP2_H
#define 	MIDTERMP2_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>

using namespace std;

const int NUM_STUDENTS = 10;
const int NUM_SCORES = 3;

class Student
{
	private:
		int ID;
    string sname;
    vector<double> scores;

  public:
    Student(){}

    int getID(void) 
    {
      return ID;
    }
    string getSName(void) 
    {
      return sname;
    }
    vector<double> getScores(void) 
    {
      return scores;
    }
    double getTotalScore(void)
    {
      double totalScore = 0;
      for(int i=0; i<scores.size(); i++) 
      {
        totalScore += scores[i];
      }
      return totalScore;
    }
    
    void setID(int ID) 
    {
      this->ID = ID;
    }
    void setSName(string sname) 
    {
      this->sname = sname;
    }
    void setScores(vector<double> scores) 
    {
      this->scores = scores;
    }

    void printStudent(void)
    {
      cout << ID << "\t" << sname << "\t";
      for(int i=0; i<scores.size(); i++)
      {
        cout << scores[i] << "\t";
      }
      cout << endl;
    }
};

#endif

//Reading test subjects from a file "Students2.txt" for easyer testing 
void makeStudents(Student students[], int N)
{
  ifstream ifs;

  ifs.open("Students2.txt");
  if(ifs.fail())
  {
    cerr << "File open error\n";
    exit(0);
  }
  for(int i=0; i<N; i++)
  {
    int id;
    string sname;
    vector<double> scores;
    ifs >> id >> sname;
    for(int j=0; j<NUM_SCORES; j++)
    {
      double score;
      ifs >> score;
      scores.push_back(score);
    }
    students[i].setID(id);
    students[i].setSName(sname);
    students[i].setScores(scores);
  }
  ifs.close();
}

//function to print all student information when called
void printStudents(Student students[], int N)
{
  for(int i=0; i<N; i++)
  {
    students[i].printStudent();
  } 
  cout << "======== End of the Information ======== \n\n\n";
}

//function to sort student in descending order by their total scores when called
void sortStudentsByScoreDesc(Student students[], int N)
{
  double sum1 = 0;
  double sum2 = 0;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N-1; j++)
		{
      sum1 = students[j].getTotalScore();
      sum2 = students[j+1].getTotalScore();
			if (sum1 < sum2)
      {	
			  swap(students[j], students[j+1]);
      }
		}
	}
}

//fucntion to sort student by their ID in ascending order when called prior to the binarySearch
void sortStudentsByIDAsc(Student students[], int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N-1; j++)
		{
			if (students[j].getID() > students[j+1].getID())
      {	
			  swap(students[j], students[j+1]);
      }
		}
	}
}

//binary search function to look for the specific student that user like to view
Student* binarySearch(Student students[], int N, int target)
{
  int first, last, mid;

  first = 0;
  last = N-1;

  while ( first <= last) 
  {
    mid = (first + last) / 2;
    // cout << first << " " << mid << " " << last << endl;
    if (target == students[mid].getID())
    {
      return &students[mid];
    }
    if (target < students[mid].getID())
    {
      last = mid - 1;
    }
    else 
    {
      first = mid + 1;
    }
  }
  
  return NULL;
}