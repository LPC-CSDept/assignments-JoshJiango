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