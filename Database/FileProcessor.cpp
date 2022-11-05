/*
Kaitlyn Vetica
CPSC 350-03
Creates a FileProcessor class using Faculty.h
Instantiates constructor, destructor, and all other methods previously declared in FileProcessor.h.
Creates the trees from files to be used in Menu, and also writes the trees back to the same files
when program is complete and exitted.
*/

#include <stdio.h>
#include "FileProcessor.h"

#include <fstream>
#include <iostream>

using namespace std;

/*
Default constructor for FileProcessor
Check to see if files exist - if not make it
*/
FileProcessor::FileProcessor(){
    stuFile = "studentTable.txt";
    facFile = "facultyTable.txt";
    ifstream sf(stuFile.c_str());
    if(sf.good()){
        studFileExists = true;
        sf.close();
    }
    else{
        ofstream out_file;
        out_file.open(stuFile);
        out_file.close();
    }
    ifstream ff(facFile.c_str());
    if(ff.good()){
        facFileExists = true;
        ff.close();
    }
    else{
        ofstream out_file;
        out_file.open(facFile);
        out_file.close();
    }
}

/*
Destructor for FileProcessor
*/
FileProcessor::~FileProcessor() {}

/*
processStuFile 
Processes the given student file called studentTable.txt and creates a tree based on the 
file's contents. Student's info is listed in specific order so the method can read from it
and create the student objects correctly.
First line in file is the number of students in the tree. Following lines are the info of all
student objects. 
@return BST<Student>* - Returns the created Student tree from the info in the file 
*/
BST<Student>* FileProcessor::processStuFile()
{
    ifstream in_file;

    in_file.open(stuFile);

    bool isEmpty = in_file.peek() == EOF;
    if(isEmpty){
        BST<Student>* fileEmpty = new BST<Student>();
        return fileEmpty;
    }

    if (!in_file.is_open())
        cout << "Could not open file." << stuFile << endl;

    BST<Student> *studentTree = new BST<Student>();

    // number of students in file
    string num;
    getline(in_file, num);
    int numStu = stoi(num);

    for (int i = 0; i < numStu; i++)
    {
        string newData;

        getline(in_file, newData);
        int stuId = stoi(newData);

        getline(in_file, newData);
        string stuName = newData;

        getline(in_file, newData);
        string stuLevel = newData;

        getline(in_file, newData);
        double stuGpa = stod(newData);

        getline(in_file, newData);
        string stuMajor = newData;

        getline(in_file, newData);
        int stuAdvisor = stoi(newData);

        getline(in_file, newData);

        Student newStu = Student(stuId, stuName, stuLevel, stuMajor, stuGpa, stuAdvisor);
        studentTree->insert(new TreeNode<Student>(newStu.getID(), newStu));
    }

    in_file.close();
    return studentTree;
}

/*
processFacFile 
Processes the given faculty file called facultyTable.txt and creates a tree based on the 
file's contents. Faculty's info is listed in specific order so the method can read from it
and create the faculty objects correctly.
First line in file is the number of faculty members in the tree. Following lines are the info of all
faculty objects. 
@return BST<Faculty>* - Returns the created Faculty tree from the info in the file 
*/
BST<Faculty>* FileProcessor::processFacFile(){
    ifstream in_file;

    in_file.open(facFile);
    bool isEmpty = in_file.peek() == EOF;
    if(isEmpty){
        BST<Faculty>* fileEmpty = new BST<Faculty>();
        return fileEmpty;
    }


    if (!in_file.is_open())
        cout << "Could not open file" << facFile << endl;

    BST<Faculty> *facultyTree = new BST<Faculty>();
    DLList<int> *facultyIds = new DLList<int>();

    string num;
    getline(in_file, num);
    int numFac = stoi(num);

    for (int i = 0; i < numFac; i++)
    {
        string newData;

        getline(in_file, newData);
        int facId = stoi(newData);

        getline(in_file, newData);
        string facName = newData;

        getline(in_file, newData);
        string facLevel = newData;

        getline(in_file, newData);
        string facDep = newData;

        DLList<int>* adIdsList = new DLList<int>();

        getline(in_file, newData);
        int numAdvisees = stoi(newData);
        for(int i = 0; i < numAdvisees; i++){
            getline(in_file, newData);
            adIdsList->insertBack(stoi(newData));
        }

        getline(in_file, newData);

        Faculty newFac = Faculty(facId, facName, facLevel, facDep, adIdsList);
        facultyTree->insert(new TreeNode<Faculty>(newFac.getID(), newFac));
    }

    in_file.close();
    return facultyTree;
}

/*
writeStuFile
Writes the student tree back into the same file with the same order that was provided in
processStuFile, so that it can read from the file again later.
@param BST<Student>* stuTree - The tree to be written to file
*/
void FileProcessor::writeStuFile(BST<Student> *stuTree)
{
    ofstream out_file;

    out_file.open(stuFile);
    if (!out_file.is_open())
        cout << "Could not open file." << stuFile << endl;

    int numStu = stuTree->length();
    DLList<Student> *studentsInTree = new DLList<Student>();

    // order: stuId, stuName, stuLevel, stuMajor, stuGpa, stuAdvisor

    out_file << to_string(numStu) << endl;
    studentsInTree = stuTree->inOrder(stuTree->getRoot());

    for (int i = 0; i < numStu; i++)
    {
        Student currStu = studentsInTree->removeFront();
        out_file << to_string(currStu.getID()) << endl;
        out_file << currStu.getName() << endl;
        out_file << currStu.getClass() << endl;
        out_file << to_string(currStu.getGPA()) << endl;
        out_file << currStu.getMajor() << endl;
        out_file << to_string(currStu.getAdvisorID()) << endl;
        out_file << endl;
    }

    out_file.close();
}

/*
writeFacFile
Writes the faculty tree back into the same file with the same order that was provided in
processFacFile, so that it can read from the file again later.
@param BST<Faculty>* facTree - The tree to be written to file
*/
void FileProcessor::writeFacFile(BST<Faculty> *facTree)
{
    ofstream out_file;

    out_file.open(facFile);
    if (!out_file.is_open())
        cout << "Could not open file" << facFile << endl;

    int numFac = facTree->length();
    DLList<Faculty> *facultyInTree = new DLList<Faculty>();

    // order: facId, facName, facLevel, facDep, adviseeList 

    out_file << numFac << endl;

    facultyInTree = facTree->inOrder(facTree->getRoot());

    for (int i = 0; i < numFac; i++)
    {
        Faculty currFac = facultyInTree->removeFront();
        DLList<int>* currFacAdviseeList = currFac.getAdviseeList();
        int listLength = currFacAdviseeList->length();
        out_file << to_string(currFac.getID()) << endl;
        out_file << currFac.getName() << endl;
        out_file << currFac.getLevel() << endl;
        out_file << currFac.getDepartment() << endl;
        out_file << currFacAdviseeList->length() << endl;
        for(int i = 0; i < listLength; i++){
            out_file << to_string(currFacAdviseeList->removeFront()) << endl;
        }
        out_file << endl;
    }

    out_file.close();
}