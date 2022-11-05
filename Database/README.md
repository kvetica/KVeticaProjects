# Database
Database program incorporating Binary Search Trees and List Stacks. 

Student and faculty database. Every student is associated with one faculty member as their advisor, and every advisor has a list of student(s) as their advisees. Identifying information about the students and advisors are stored as nodes. 

Program saves the last instance of the Trees/Menu (student and faculty) when program closes successfully. Next time program runs, it reads from the studentTable and facultyTable files and rebuilds the trees with the same information. 

## Identifying Information

* Name: Kaitlyn Vetica
* Email: kaitlynvgolf@gmail.com
* Course: CPSC 350 - Data Structures
* Date: Spring 2021
* Assignment: Database

## Source Files

* Faculty.cpp
* FileProcessor.cpp
* mainprogram.cpp
* Menu.cpp
* Student.cpp
* TreeDB.cpp

## References

* cplusplus.com
* https://www.geeksforgeeks.org/operator-overloading-c/
* https://www.daniweb.com/programming/software-development/threads/250669/check-if-file-is-empty

## Known Errors

* Produces error when percentage is entered as a decimal. When prompted for percentage filled, enter as whole number (i.e. 35, 25, 50).
* Cannot open files when .txt is not included in user input.

## Example Input and Output 

* Example student and faculty tables for running the program given in studentTable.txt and facultyTable.txt

## Build Insructions

* <code> g++ -std=c++11 *.cpp -o out.o </code>

## Execution Instructions

* <code> ./out.o </code>
* The order that FileProcessor reads the file to make the tree is in FileProcessor process file methods. Example of this order is given in facultyTable.txt and studentTable.txt. To start from no file, remove those files first. 
* IDs cannot be -1. The program assumes that the ID will never be equal to -1, so we use it to check that a student/faculty member does not exist in the table. 
* When adding a new faculty member, you cannot give it a student ID that does not exist in the student table (you can, it just doesn't do anything). If you give a student ID that does not exist, it will create the faculty member but it will not include that student ID in the advisee list and it will not create a new student in student table with that ID.
