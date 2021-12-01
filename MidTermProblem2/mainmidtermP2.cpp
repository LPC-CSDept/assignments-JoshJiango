#include "midtermP2.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
  double target;
  Student students[NUM_STUDENTS];

  // Call makeStudents function to read infor from txt file 
  makeStudents(students, NUM_STUDENTS);
  cout << endl;
  
  // Printing and display the original input of the reading from the txt file
  cout << "Below Are The 10 Students With Their Information (ID, Name, 3 Test Scores):" << endl; 
  printStudents(students, NUM_STUDENTS);

  // Sort Student List by descenind total scores
  sortStudentsByScoreDesc(students, NUM_STUDENTS);
  cout << "All Students With The Descending Order Of Total Scores:" << endl;
  printStudents(students, NUM_STUDENTS);

  // Sort Student List by asencding ID in preperation for binary search on ID
  sortStudentsByIDAsc(students, NUM_STUDENTS);
  cout << "All Students With The Asecending Order Of Student ID:" << endl;
  printStudents(students, NUM_STUDENTS);
  
  // Ask user for input and get the input infor ID in this case
  cout << "Please Enter The 8 Digit ID Of The Student You Want To Reivew: " << endl;
  cin >> target;

  Student* searchResult = binarySearch(students, NUM_STUDENTS, target);

  if (searchResult != NULL) 
  {
    cout << "\nThe Student Information: \n";
    searchResult->printStudent();
  } 
  else 
  {
    cout << "The ID You Have Entered Is Invalid, Please Try Again By Running The Program." << endl;
  }
}