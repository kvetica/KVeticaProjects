/*
Kaitlyn Vetica
CPSC 350-03
Mainprogram for the database. Displays the options to the user and permits the user to select
what option they want to do with the database and executes the commands. The methods for these
options that are displayed and run are from Menu class. This class just runs those methods 
and formats output so the correct input is given to use the Menu methods.
*/

#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "FileProcessor.h"
#include "Menu.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
main
Displays all options and gathers input for Menu methods from user when options are selected. 
Runs all Menu methods according to user input.
@return int - Returns 0 when program is complete and has been exitted.
*/
int main(){
    Menu* m = new Menu();
    cout << "----- Welcome to the Student and Faculty Database -----" << endl;
    string userInput = "0";
    int commandRun = 0;
    // while the user does not want to exit the program, continue giving options and allowing 
    // user to select options to execute 
    while(userInput != "13"){
        m->databaseOptions();
        cout << "Enter the corresponding number to execute command: ";
        getline(cin, userInput);

        // Option 1 
        // Print all students and their information (ascending id)
        if(userInput == "1"){
            m->printStudents();
        }

        // Option 2 
        // Print all faculty and their information (ascending id)
        else if(userInput == "2"){
            m->printFaculty();
        }

        // Option 3
        // Find and display student info given student id
        else if(userInput == "3"){
            string stuIdInput = "";
            cout << "Enter student ID: ";
            getline(cin, stuIdInput);
            commandRun = m->displayStudent(stoi(stuIdInput));
        }

        // Option 4
        // Find and display faculty info given faculty id
        else if(userInput == "4"){
            string facIdInput = "";
            cout << "Enter faculty ID: ";
            getline(cin, facIdInput);
            commandRun = m->displayFaculty(stoi(facIdInput));
        }

        // Option 5
        // Given a student's id, print the name and info of their fac advisor
        else if(userInput == "5"){
            string stuIdInput = "";
            cout << "Enter student ID: ";
            getline(cin, stuIdInput);
            commandRun = m->displayStudentsAdvisor(stoi(stuIdInput));
        }

        // Option 6
        // Given a fac id, print the name and info of their advisees 
        else if(userInput == "6"){
            string facIdInput = "";
            cout << "Enter faculty ID: ";
            getline(cin, facIdInput);
            commandRun = m->displayAdvisorsStudents(stoi(facIdInput));
        }

        // Option 7
        // Add a new student
        else if(userInput == "7"){
            Student newStu;
            string stuName = "";
            string stuId = "";
            string stuClassLevel = "";
            string stuMajor = "";
            string stuGpa = "";
            string stuAdId = "";

            cout << "Enter new Student's ID: ";
            getline(cin, stuId);
            cout << "Enter new Student's name: ";
            getline(cin, stuName);
            cout << "Enter new Student's class level: ";
            getline(cin, stuClassLevel);
            cout << "Enter new Student's major: "; 
            getline(cin, stuMajor);
            cout << "Enter new Student's GPA: "; 
            getline(cin, stuGpa);
            cout << "Enter new Student's advisor's ID: ";
            getline(cin, stuAdId);

            newStu = Student(stoi(stuId), stuName, stuClassLevel, stuMajor, stod(stuGpa), stoi(stuAdId));
            commandRun = m->addNewStudent(newStu);
        }

        // Option 8 
        // Delete a student given the id
        else if(userInput == "8"){
            string stuIdInput = "";
            cout << "Enter student ID to delete: ";
            getline(cin, stuIdInput);
            m->deleteStudent(stoi(stuIdInput));
        }

        // Option 9
        // Add new faculty member 
        else if(userInput == "9"){
            Faculty newFac;
            string facId = "";
            string facName = "";
            string facLevel = "";
            string facDepartment = "";
            string adviseeId = "";
            DLList<int>* facAdviseeIds = new DLList<int>();

            cout << "Enter faculty member ID: ";
            getline(cin, facId);
            cout << "Enter faculty member name: ";
            getline(cin, facName);
            cout << "Enter faculty member level: ";
            getline(cin, facLevel);
            cout << "Enter faculty member department: ";
            getline(cin, facDepartment);
            cout << "Enter all advisee IDs by doing the following: " << endl;
            cout << "Enter advisee ID, hit ENTER, and continue entering IDs." << endl;
            cout << "When finished, enter 0 and hit ENTER." << endl;
            while(adviseeId != "0"){
                cout << "Enter advisee ID: ";
                getline(cin, adviseeId);
                if(adviseeId == "0"){
                    break;
                }
                else{
                    facAdviseeIds->insertBack(stoi(adviseeId));
                }
            }
            newFac = Faculty(stoi(facId), facName, facLevel, facDepartment, facAdviseeIds);
            m->addNewFaculty(newFac);
        }

        // Option 10
        // Delete faculty member given id
        else if(userInput == "10"){
            string facIdInput = "";
            cout << "Enter faculty member ID to remove: ";
            getline(cin, facIdInput);
            m->deleteFaculty(stoi(facIdInput));
        }

        // Option 11 
        // Change a student's advisor given the ids
        else if(userInput == "11"){
            string stuIdInput = "";
            string facIdInput = "";
            cout << "Enter student's ID to change the advisor of: ";
            getline(cin, stuIdInput);
            cout << "Enter new advisor's ID of student: ";
            getline(cin, facIdInput);

            commandRun = m->changeStuAdvisor(stoi(stuIdInput), stoi(facIdInput), false);
        }

        // Option 12
        // Remove an advisee from a faculty member given the ids 
        else if(userInput == "12"){
            string stuIdInput = "";
            string facIdInput = "";
            cout << "Enter faculty member's ID to change advisee of: ";
            getline(cin, facIdInput);
            cout << "Enter student's ID to remove from advisor: ";
            getline(cin, stuIdInput);

            commandRun = m->removeStuFromAdvisor(stoi(stuIdInput), stoi(facIdInput));
        }

        // Anything entered that is not an option 
        // Have user try again
        else if(userInput != "13"){
            cout << "Not a valid option selection." << endl;
            cout << "Please try again." << endl;
        }

    }

    // Option 13
    // Write trees to files and exit database.
    if (userInput == "13"){
        cout << "Saving tables..." << endl;
        m->exit();
        cout << "Menu closed." << endl;
        return 0;
    }

    return 0;
}