/*
Kaitlyn Vetica
CPSC 350-03
Creates a Faculty class using Faculty.h
Instantiates constructor, destructor, and all other methods previously declared in Faculty.h.
Overloads constructors for ==, < and >
*/

#include "Faculty.h"
#include <iostream>
#include <string>
using namespace std;

/*
Default constructor 
*/
Faculty::Faculty(){
    facultyID = -1;
    name = "None";
    level = "Lecturer";
    department = "Undeclared";
    allStudentIds = new DLList<int>();
}

/*
Overloaded constructor. Creates faculty object given list of parameters.
@param int id - ID of faculty member 
@param string userName - Name of faculty member 
@param string userLevel - Level of fac
@param string dep - Department of fac 
@param DLList<int>* adIds - List of the advisee IDs of the fac
*/
Faculty::Faculty(int id, string userName, string userLevel, string dep, DLList<int>* adIds){
    facultyID = id;
    name = userName;
    level = userLevel;
    department = dep;
    allStudentIds = adIds;
}

/*
Destructor
*/
Faculty::~Faculty(){}

/*
printInfo 
Prints the ID and info of the faculty member in specific format 
*/
void Faculty::printInfo(){
    cout << "Faculty ID: " << facultyID << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Department: " << department << endl;
    DLList<int>* tempIdsList = allStudentIds;
    cout << "Advisee IDs: ";
    for(int i = 0; i < tempIdsList->length(); i++){
        int tempId = tempIdsList->removeFront();
        cout << tempId << " / ";
        tempIdsList->insertBack(tempId);
    }
    cout << endl;
    cout << endl;
}

/*
getID
Returns the ID of the faculty member
@return int - ID of faculty member 
*/
int Faculty::getID(){
    return facultyID;
}

/*
getName
Returns the name of the faculty member 
@return string - Name of fac member 
*/
string Faculty::getName(){
    return name;
}

/*
getLevel
Returns the level of the faculty member 
@return string - Level of fac member 
*/
string Faculty::getLevel(){
    return level;
}

/*
getDepartment 
Returns the department of the faculty member 
@return string - Department of fac 
*/
string Faculty::getDepartment(){
    return department;
}

/*
getAdviseeList 
Returns the list of the advisee IDs of the faculty member 
@return DLList<int>* - List of advisee IDs as ints 
*/
DLList<int>* Faculty::getAdviseeList(){
    return allStudentIds;
}

/*
setAdviseeList 
Sets the advisee list of the faculty member given a new list 
@param DLList<int>* newList - New list of advisee IDs to set faculty member's list to
*/
void Faculty::setAdviseeList(DLList<int>* newList){
    allStudentIds = newList;
}

/*
operator==
Overloaded operator for ==. Compares if the IDs are the same 
@param Faculty f - Faculty member to compare to 
@return bool - Returns true if the same, returns false if not 
*/
bool Faculty::operator==(Faculty f){
    return(this->facultyID == f.getID());
}

/*
operator>
Overloaded operator for >. Compares if the current ID is greater than the given ID
@param Faculty f - Faculty member to compare to 
@return bool - Returns T if greater, F if not
*/
bool Faculty::operator>(Faculty f){
    return (this->facultyID > f.getID());
}

/*
operator<
Overloaded operator for <. Compares if the current ID is less than the given ID 
@param Faculty f - Faculty member to compare to 
@return bool - Returns T if less than, F if not 
*/
bool Faculty::operator<(Faculty f){
    return (this->facultyID < f.getID());
}