/*
Kaitlyn Vetica
CPSC 350-03
Header file for Student class. Defines constructor, destructor,
printInfo, getter, setter, and overloaded operator methods.
Declares private variables used in Student class. 
*/

#include <string>

using namespace std;

#ifndef Student_h
#define Student_h

class Student{
//   Student records contain a unique student 
// ID (an integer), a string name field, a string level field (Freshman, Sophomore, etc.), a string 
// major field, a double GPA field, and an integer advisor field, which will contain the faculty 
// ID of their advisor.
    int studentID;
    string name;
    string classLevel;
    string major;
    double GPA;
    int advisor;
  
public:
  Student();
  Student(int id, string userName, string userClass, string userMajor, double userGPA, int userAdvisor);  
  ~Student();
  void printInfo();
  void setAdvisor(int newAdvisor);
  int getID();
  string getName();
  string getClass();
  string getMajor();
  double getGPA();
  int getAdvisorID();
  // overloaded op for ==, >, <
  bool operator==(Student s);
  bool operator>(Student s);
  bool operator<(Student s);
  // int writeFile(); // input
  // int readFile(); // output
};

#endif