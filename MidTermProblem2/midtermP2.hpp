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