/*
Kaitlyn Vetica
CPSC 350-03
Creates a TreeDB class using TreeDB.h
Instantiates constructor, destructor, and all other methods previously declared in TreeDB.h.
Stores student and faculty trees as one object - used for rollback method.
*/

#include "TreeDB.h"
#include "DLList.h"

#include <iostream>
using namespace std;

/*
Default constructor
*/
TreeDB::TreeDB(){
    studentTree = BST<Student>();
    facultyTree = BST<Faculty>();
    // pStudentTree = new BST<Student>();
    // pFacultyTree = new BST<Faculty>();
}

/*
Overloaded constructor 
Setting the nonpointer trees to be the dereferenced pointer trees. 
*/
TreeDB::TreeDB(BST<Student>* stuTree, BST<Faculty>* facTree){
    // studentTree = *stuTree;
    // facultyTree = *facTree;
    DLList<Student>* stuList = stuTree->inOrder(stuTree->getRoot());
    int stuListLength = stuList->length();
    /*
    Going through and making new TreeNodes so they are new pointers instead of the pointers 
    that are still in the current tree. This is so the pointers don't continue changing 
    after this object is created. 
    **** Known Error: Caused segmentation faults. Doesn't work when printing the tree after rollback.
    */
    for(int i = 0; i < stuListLength; i++){
        Student currStu = stuList->removeFront();
        studentTree.insert(new TreeNode<Student>(currStu.getID(), currStu));
    }

    DLList<Faculty>* facList = facTree->inOrder(facTree->getRoot());
    int facListLength = facList->length();
    for(int i = 0; i < facListLength; i++){
        Faculty currFac = facList->removeFront();
        /*
        Setting the adviseeList (pointer in Faculty object) to new pointer so it 
        does not continue changing after this object is created.
        **** Known Error: Segmentation fault when adding new Faculty object. Issue with storeChanges method.
        */
        // DLList<int> adviseeList = *currFac.getAdviseeList();
        // currFac.setAdviseeList(&adviseeList);
        facultyTree.insert(new TreeNode<Faculty>(currFac.getID(), currFac));
    }
}

/*
Destructor
*/
TreeDB::~TreeDB(){}

/*
getStudentTree
Returns the student tree
@return BST<Student> - Student tree (nonpointer)
*/
BST<Student> TreeDB::getStudentTree(){
    return studentTree;
}

/*
getFacultyTree
Returns the faculty tree
@return BST<Faculty> - Faculty tree (nonpointer)
*/
BST<Faculty> TreeDB::getFacultyTree(){
    return facultyTree;
}