/*
Kaitlyn Vetica
CPSC 350-03
Header file for Faculty class. Defines constructor, destructor,
printInfo, getter, setter, and overloaded operator methods.
Declares private variables used in Faculty class. 
*/

#ifndef Faculty_h
#define Faculty_h


#include <string>
#include "DLList.h"
using namespace std;

class Faculty{
    int facultyID;
    string name;
    string level;
    string department;
    DLList<int>* allStudentIds;
    
public:
  Faculty();
  Faculty(int id, string userName, string userLevel, string dep, DLList<int>* adIds);
  ~Faculty();
  void printInfo();
  int getID();
  string getName();
  string getLevel();
  string getDepartment();
  DLList<int>* getAdviseeList();
  void setAdviseeList(DLList<int>* newList);
  // Faculty getFacultyMember(int id);
  // overloaded op for ==, >, <
  bool operator==(Faculty f);
  bool operator>(Faculty f);
  bool operator<(Faculty f);
  
};
#endif