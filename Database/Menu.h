/*
Kaitlyn Vetica
CPSC 350-03
Header file for Menu class. Defines constructor, destructor,
and all database option methods.
Declares private variables used in Menu class. 
*/

#ifndef Menu_h
#define Menu_h

#include <string>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "DLList.h"
#include "FileProcessor.h"
#include "LStack.h"
#include "TreeDB.h"
using namespace std;

class Menu{
private:
  BST<Student>* studentTree;
  BST<Faculty>* facultyTree;
  FileProcessor* fPro;
  int rollbackCounter;
  LStack<TreeDB>* rollbackStack;

  
public:
  Menu();
  ~Menu();

  BST<Student>* getStuTree();

  BST<Faculty>* getFacTree();

  // print all students and their info (ascending id)
  void printStudents();

  // print all fac and their info (ascending id)
  void printFaculty();

  // find and display student info given student id
  int displayStudent(int stuId);

  // find and display fac info given fac id 
  int displayFaculty(int facId);

  // given a student's id, print the name and info of their fac advisor 
  int displayStudentsAdvisor(int stuId);

  // given fac id, print the name and info of ALL their students 
  int displayAdvisorsStudents(int facId);

  // add a new student 
  int addNewStudent(Student stu);

  // delete a student given the id 
  void deleteStudent(int stuId);

  // add a new faculty member 
  int addNewFaculty(Faculty fac);

  // delete a faculty member given fac id 
  void deleteFaculty(int facId);

  // change a student's advisor given stu id and new fac id 
  int changeStuAdvisor(int stuId, int facId, bool goThru);

  // remove an advisee from a faculty member given the stu id and fac id 
  int removeStuFromAdvisor(int stuId, int facId);

  // give option to user to undo up to the last 5 changes 
  void rollback();

  // end simulation   
  void exit();

  // cout statement of options for user 
  void databaseOptions();

  void storeChanges(BST<Student>* ogStuTree, BST<Faculty>* ogFacTree);

};

#endif