/*
Kaitlyn Vetica
CPSC 350-03
Header file for TreeDB class. Defines constructor, destructor,
and getter methods.
Declares private variables used in TreeDB class. 
*/

#ifndef TreeDB_H
#define TreeDB_H

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;

class TreeDB{
    // BST<Student> studentTree;
    // BST<Faculty> facultyTree;
    // BST<Student> pStudentTree;
    // BST<Faculty> pFacultyTree;

public:
    BST<Student> studentTree;
    BST<Faculty> facultyTree;
    TreeDB();
    TreeDB(BST<Student>* stuTree, BST<Faculty>* facTree);
    ~TreeDB();
    BST<Student> getStudentTree();
    BST<Faculty> getFacultyTree();

};


#endif