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

}