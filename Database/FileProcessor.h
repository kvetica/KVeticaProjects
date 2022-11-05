/*
Kaitlyn Vetica
CPSC 350-03
Header file for FileProcessor class. Defines constructor, destructor,
process file and write file methods.
Declares private variables used in FileProcessor class. 
*/

#include <fstream>
#include <iostream>
#include <string>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

using namespace std;

class FileProcessor{
private:
    string stuFile;
    string facFile;
    bool studFileExists;
    bool facFileExists;

public:
  FileProcessor();
  ~FileProcessor();
  BST<Student>* processStuFile();
  BST<Faculty>* processFacFile();
  void writeStuFile(BST<Student>* stuTree);
  void writeFacFile(BST<Faculty>* facTree);
};

#endif 