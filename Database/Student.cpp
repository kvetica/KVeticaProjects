/*
Kaitlyn Vetica
CPSC 350-03
Creates a Student class using Student.h
Instantiates constructor, destructor, and all other classes previously declared in Student.h.
Overloads constructors for ==, < and >
*/

#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Default constructor 
*/
Student::Student(){
    studentID = -1;
    name = "None";
    classLevel = "Freshman";
    major = "Undeclared";
    GPA = 4.0;
    advisor = -1;
}

/*
Overloaded constructor 
*/
Student::Student(int id, string userName, string userClass, string userMajor, double userGPA, int userAdvisor){
    studentID = id;
    name = userName;
    classLevel = userClass;
    major = userMajor;
    GPA = userGPA;
    advisor = userAdvisor;
}

/*
Destructor
*/
Student::~Student(){}

/*
printInfo
Prints id and all info of student in formatted form 
*/
void Student::printInfo(){
    cout << "Student ID: " << studentID << endl;
    cout << "Name: " << name << endl;
    cout << "Advisor ID: " << advisor << endl;
    cout << "Class Level: " << classLevel << endl;
    cout << "Major: " << major << endl;
    cout << "GPA : " << GPA << endl;
    cout << endl;
}

/*
setAdvisor
Sets the advisor of the student 
@param int newAdvisor - ID of the new advisor for the student 
*/
void Student::setAdvisor(int newAdvisor){
    advisor = newAdvisor;
}

/*
getID
Returns the ID of the student 
@return int - ID of the student 
*/
int Student::getID(){
    return studentID;
}

/*
getName
Returns the name of the student
@return string - name of the student 
*/
string Student::getName(){
    return name;
}

/*
getClass
Returns the class of the student
@return string - Class of the student 
*/
string Student::getClass(){
    return classLevel;
}
  
/*
getMajor
Returns the major of the student 
@return string - Major of the student 
*/
string Student::getMajor(){
    return major;
}

/*
getGPA
Returns the GPA of the student 
@return double - GPA of student 
*/
double Student::getGPA(){
    return GPA;
}

/*
getAdvisorID
Returns the ID of the student's advisor 
@return int - Advisor ID 
*/
int Student::getAdvisorID(){
    return advisor;
}

/*
operator==
Overloaded operator for ==. Compares if the IDs are the same 
@param Student s - Student to compare to 
@return bool - Returns true if the same, returns false if not 
*/
bool Student::operator==(Student s){
    return(this->studentID == s.getID());
}

/*
operator>
Overloaded operator for >. Compares if the current ID is greater than the given
@param Student s - Student to compare to 
@return bool - Returns true if greater than, returns false if not 
*/
bool Student::operator>(Student s){
    return(this->studentID > s.getID());
}

/*
operator<
Overloaded operator for <. Compares if the current ID is less than the given 
@param Student s - Student to compare to 
@return bool - Returns true if less than, returns false if not 
*/
bool Student::operator<(Student s){
    return(this->studentID < s.getID());
}