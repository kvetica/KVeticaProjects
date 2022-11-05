/*
Kaitlyn Vetica
CPSC 350-03
Creates a Menu class using Menu.h
Instantiates constructor, destructor, and all other methods previously declared in Menu.h.
Uses trees created in FileProcessor and changes/displays the trees based upon what methods 
are used in mainprogram. This class holds all the methods for actually changing the trees of the
database.
*/


#include "Menu.h"
#include "FileProcessor.h"

#include <iostream>
using namespace std;

/*
Default constructor 
*/
Menu::Menu(){
    fPro = new FileProcessor();
    facultyTree = fPro->processFacFile();
    studentTree = fPro->processStuFile();
    rollbackCounter = 0;
    rollbackStack = new LStack<TreeDB>(0);

}

/*
Destructor
*/
Menu::~Menu(){}

/*
getStuTree
Returns the student tree 
@return BST<Student>* - Student tree pointer 
*/
BST<Student>* Menu::getStuTree(){
    return studentTree;
}

/*
getFacTree
Returns the faculty tree
@return BST<Faculty>* - Faculty tree pointer
*/
BST<Faculty>* Menu::getFacTree(){
    return facultyTree;
}

/*
printStudents
Prints all students and their info (ascending id) 
Uses printInfo() from student class to format 
*/
void Menu::printStudents(){
    cout << "----- All Students -----" << endl;
    // cout << "1" << endl;
    DLList<Student>* stuList = studentTree->inOrder(studentTree->getRoot());
    // cout << "2" << endl;
    int listLength = stuList->length();
    // cout << listLength << endl;
    
    for(int i = 0; i < listLength; i++){
        Student stuCurr = stuList->removeFront();
        stuCurr.printInfo();
    }
}

/*
printFaculty
Prints all faculty members and their info (ascending id)
Uses printInfo() from faculty class to format
*/
void Menu::printFaculty(){
    cout << "----- All Faculty -----" << endl;
    DLList<Faculty>* facList = facultyTree->inOrder(facultyTree->getRoot());
    int listLength = facList->length();
    for(int i = 0; i < listLength; i++){
        Faculty facCurr = facList->removeFront();
        facCurr.printInfo();
    }
}

/*
displayStudent
Finds and displays student info given the student id 
@param int stuId - Student's id we want to find 
@return int - Returns 1 if completed, 0 if not 
*/
int Menu::displayStudent(int stuId){
    Student foundStu = studentTree->find(stuId);
    // standard ID for a student is -1 if it is not found 
    if(foundStu.getID() == -1){
        cout << "Student not found." << endl;
        return 0;
    }
    cout << "----- Found Student -----" << endl;
    foundStu.printInfo();
    return 1;
}

/*
displayFaculty
Finds and displays faculty info given the faculty id 
@param int facId - Faculty's id we want to find 
@return int - Returns 1 if completed, 0 if not 
*/
int Menu::displayFaculty(int facId){
    Faculty foundFac = facultyTree->find(facId);
    // stanrdard ID for a faculty member is -1 if it is not found 
    if(foundFac.getID() == -1){
        cout << "Advisor not found." << endl;
        return 0;
    }
    cout << "----- Found Advisor -----" << endl;
    foundFac.printInfo();
    return 1;
}

/*
displayStudentAdvisor
Given a student's id, print the name and info of their faculty advisor. 
@param int stuId - Student id we want to print their advisor's info of 
@return int - Returns 1 if completed, 0 if not 
*/
int Menu::displayStudentsAdvisor(int stuId){
    Student stu = studentTree->find(stuId);
    if(stu.getID() == -1){
        cout << "Student not found." << endl;
        return 0;
    }
    int stuAdvisorId = stu.getAdvisorID();
    Faculty stuAdvisor = facultyTree->find(stuAdvisorId);
    stuAdvisor.printInfo();
    return 1;
}

/*
displayAdvisorsStudents 
Given the faculty id, print the name and info of all of their student advisees 
@param facId - Faculty ID we want the advisees of 
@return int - Returns 1 if completed, 0 if not 
*/
int Menu::displayAdvisorsStudents(int facId){
    Faculty fac = facultyTree->find(facId);
    if(fac.getID() == -1){
        cout << "Advisor not found" << endl;
        return 0;
    }
    DLList<int>* adviseeList = fac.getAdviseeList();
    string facName = fac.getName();
    if(adviseeList->length() == 0){
        cout << facName << " has no advisees" << endl;
        return 1;
    }

    cout << "List of Advisees for " << facName << endl;
    for(int i = 0; i < adviseeList->length(); i++){
        int stuId = adviseeList->removeFront();
        Student currStu = studentTree->find(stuId);
        currStu.printInfo();
        adviseeList->insertBack(stuId);
    }
    return 1;
}

/*
addNewStudent
Adds new student to student tree 
@param Student stu - Student to add to tree 
@return int - Returns 1 if completed, 0 if not 
*/
int Menu::addNewStudent(Student stu){
    Student checkStu = studentTree->find(stu.getID());
    // if id != -1, student with that ID already exists in the tree and cannot be added 
    if(checkStu == stu){ //************
        cout << "Student with that ID already exists." << endl;
        cout << "Cannot add new student." << endl;
        return 0;
    }
    int advisorId = stu.getAdvisorID();
    Faculty advisor = facultyTree->find(advisorId);
    if(advisor.getID() == -1){
        cout << "Cannot add student. Advisor does not exist." << endl;
        return 0;
    }
    else{
        DLList<int>* adviseeList = advisor.getAdviseeList();
        adviseeList->insertBack(stu.getID());
        advisor.setAdviseeList(adviseeList);
    }
    studentTree->insert(new TreeNode<Student>(stu.getID(), stu));
    return 1;
}

/*
deleteStudent
Deletes a student from the student tree given the student id 
@param int stuId - ID of student we want to delete 
*/
void Menu::deleteStudent(int stuId){
    bool removed = false;
    // true if removed, false if did not remove (doesnt exist in tree)
    Student remStudent = studentTree->find(stuId);
    removed = studentTree->remove(stuId);

    int advisorId = remStudent.getAdvisorID();
    Faculty advisor = facultyTree->find(advisorId);
    DLList<int>* adviseeList = advisor.getAdviseeList();

    if(removed == false)
        cout << "Student does not exist. Cannot remove." << endl;
    else{
        // removing student from advisor's list 
        if(adviseeList->length() == 1){
            int removedId = adviseeList->removeFront();
        }
        else{
            int removedId = adviseeList->removeNode(stuId);
        }
        advisor.setAdviseeList(adviseeList);
        cout << "Successfully removed student." << endl;
    }
}

/*
addNewFaculty
Adds a new faculty member to faculty tree 
@param Faculty fac - Faculty member to add to tree 
@return int - Returns 1 if completed, 0 if not 
*/
int Menu::addNewFaculty(Faculty fac){
    Faculty checkFacExists = facultyTree->find(fac.getID());
    if(checkFacExists == fac){
        cout << "Faculty member with this ID already exists. Cannot add." << endl;
        return 0;
    }
    DLList<int>* adviseeList = fac.getAdviseeList();
    for(int i = 0; i < adviseeList->length(); i++){
        Student checkStuExists = studentTree->find(adviseeList->removeFront());
        if(checkStuExists.getID() == -1){
            cout << "Student with ID " << checkStuExists.getID() << " does not exist." << endl;
            cout << "Cannot add Faculty member." << endl;
            return 0;
        }
    }

    int facId = fac.getID();
    facultyTree->insert(new TreeNode<Faculty>(facId, fac));
    return 1;
}

/*
deleteFaculty
Delete a faculty member from tree given the faculty id
@param int facId - ID of faculty member to delete 
*/
void Menu::deleteFaculty(int facId){
    bool removedFaculty = false;
    Faculty temp = facultyTree->find(facId);
    if(temp.getID() == -1){
        cout << "Advisor does not exist. Cannot remove." << endl;
    }
    else{    
        DLList<int>* adviseeList = temp.getAdviseeList();
        if(adviseeList->length() != 0){
            for(int i = 0; i <= adviseeList->length(); i++){
                int stuId = adviseeList->removeFront();
                adviseeList->insertBack(stuId);
                Student stuMissingAdvisor = studentTree->find(stuId);

                // if the faculty table is empty, remove the student from the table 
                if(facultyTree->length() == 1){
                    bool treeEmpty = studentTree->remove(stuId);
                }
                else{
                    TreeNode<Faculty>* newFac = facultyTree->getRoot();
                    if(newFac->getValue() == temp){
                        TreeNode<Faculty>* nextFac = facultyTree->getSuccessor(newFac);
                        changeStuAdvisor(stuId, nextFac->getKey(), true);
                    }
                    else{
                        changeStuAdvisor(stuId, newFac->getKey(), true);
                    }
                }
            }
        }
        removedFaculty = facultyTree->remove(facId);
        cout << "Successfully removed advisor." << endl;
    }
}

// 11 change a student's advisor given stu id and new fac id
/*
changeStuAdvisor
Change a student's advisor given the student id and new faculty id 
@param int stuId - ID of student to change advisor of 
@param int facId - ID of new advisor for student 
@param bool goThru - If true, changes have already been stored for rollback. If false, 
                changes have not yet been stored so store them here.
@return int - Returns 1 if completed, 0 if not.
*/
int Menu::changeStuAdvisor(int stuId, int facId, bool goThru){
    Student changeStu = studentTree->find(stuId);
    int oldAdvisorId = changeStu.getAdvisorID();
    if(changeStu.getID() == -1){
        cout << "Student does not exist." << endl;
        return 0;
    }
    Faculty newAdvisor = facultyTree->find(facId);
    Faculty oldAdvisor = facultyTree->find(oldAdvisorId);
    if(newAdvisor.getID() == -1){
        cout << "Advisor does not exist." << endl;
        return 0;
    }   
    else{
        // removing student from old advisor's list 
        DLList<int>* oldAdviseeList = oldAdvisor.getAdviseeList();
        int removedItem = oldAdviseeList->removeNode(stuId);
        oldAdvisor.setAdviseeList(oldAdviseeList);

        // adding student to new advisor's list
        DLList<int>* adviseeList = newAdvisor.getAdviseeList();
        adviseeList->insertBack(stuId);
        newAdvisor.setAdviseeList(adviseeList);
 
        changeStu.setAdvisor(facId);
        bool removed = studentTree->remove(changeStu.getID());
        studentTree->insert(new TreeNode<Student>(changeStu.getID(), changeStu));
    }

    return 1;
}

/*
removeStuFromAdvisor
Remove a student advisee from advisor given the student and faculty id
@param int stuId - ID of student to remove from advisor 
@param int facId - ID of the faculty member we want to change advisee list of 
@return int - Returns 1 if completed, 0 if not 
*/
int Menu::removeStuFromAdvisor(int stuId, int facId){
    Faculty currAdvisor = facultyTree->find(facId);
    // checks if advisor exists in tree 
    // if ID = -1, the advisor does not exist 
    if(currAdvisor.getID() == -1){
        cout << "Advisor does not exist." << endl;
        return 0;
    }

    DLList<int>* adviseeList = currAdvisor.getAdviseeList();
    bool stuExists = adviseeList->find(stuId);
    // checks if advisee is in advisor's list 
    if(stuExists == true){
        // changes the student's advisor to the next advisor in tree 
        Faculty temp = facultyTree->find(facId);
        // if the faculty table is empty, remove the students from the table
        if (facultyTree->length() == 1){
            bool removedStudent = false;
            removedStudent = studentTree->remove(stuId);
        }
        else{
            if(facultyTree->getRoot()->getValue() == currAdvisor){
                // if(facultyTree->length() == 1){
                //     bool removedStudent = studentTree->remove(stuId);
                // }
                // else{
                    TreeNode<Faculty> *tempNode = facultyTree->getRoot();
                    TreeNode<Faculty> *newAdNode = facultyTree->getSuccessor(tempNode);
                    Faculty newAd = newAdNode->getValue();
                    int changeStuAd = changeStuAdvisor(stuId, newAd.getID(), true);
                // }
            }
            else{
                TreeNode<Faculty> *newAdNode = facultyTree->getRoot();
                Faculty newAd = newAdNode->getValue();
                int changeStuAd = changeStuAdvisor(stuId, newAd.getID(), true);
            }
        }
        // bool foundthing = adviseeList->find(stuId);
        for(int i = 0; i < adviseeList->length(); i++){
            int stuIdIt = adviseeList->removeFront();
            adviseeList->insertBack(stuIdIt);
        }
        int removedStu = adviseeList->removeNode(stuId);
        return 1;
    }   
    else{
        cout << "Student is not an advisee of the advisor." << endl;
        return 0;
    }
}


/*
exit
Write trees to files and exit program. 
*/
void Menu::exit(){
    fPro->writeStuFile(studentTree);
    fPro->writeFacFile(facultyTree);
    cout << "Tables saved to files successfully." << endl;
}

/*
databaseOptions
Prints the database options to the user in a formatted manner
*/
void Menu::databaseOptions(){
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Database Options: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)." << endl;  
    cout << "2. Print all faculty and their information (sorted by ascending id #)." << endl;
    cout << "3. Find and display student information given the students id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor." << endl; 
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id." << endl;
    cout << "9. Add a new faculty member." << endl;  
    cout << "10. Delete a faculty member given the id." << endl;  
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;  
    cout << "12. Remove an advisee from a faculty member given the ids." << endl;
    cout << "13. Exit." << endl;
}
