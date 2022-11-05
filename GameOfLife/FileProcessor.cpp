/*
Kaitlyn Vetica
CPSC 350-03
Creates a FileProcessor class using FileProcessor.h
Instantiates constructor, destructor, readFile, writeFile, and getter methods for
private variables found in class.
*/

#include "FileProcessor.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
Default constructor for FileProcessor
*/
FileProcessor::FileProcessor(){
  int arrRow = 0;
  int arrCol = 0;
}

/*
Destructor for FileProcessor
*/
FileProcessor::~FileProcessor(){}

/*
readFile function
Opens an "in_file" which holds grid row and column size, and the initial grid.
Processes through the in_file and sets the row and column and initialGen variables as needed.
@param string inputFile - The name of the file which is being read from, holds grid information
@return void - No return
*/
char** FileProcessor::readFile(string inputFile){
  ifstream in_file;
  char **initialGen;
  string line;

  in_file.open(inputFile);
  if (!in_file.is_open()) {
     cout << "Could not open file " << inputFile << endl;
  }

  if(in_file.is_open()){
    int linecount = 0;

    while(getline(in_file, line)){
      // Holds num of rows
      if(linecount == 0){
        char c = line.at(0);
        arrRow = c - '0';
        linecount++;
      }
      // Holds num of cols
      else if(linecount == 1){
        char c = line.at(0);
        arrCol = c - '0';
        linecount++;
        initialGen = new char*[arrRow];
        for(int i = 0; i < arrRow; i++){
          initialGen[i] = new char[arrCol];
        }
      }
      // Holds initialGen grid
      else{
        for (int i=0; i<arrCol; i++) {
          char c = line.at(i);
          initialGen[linecount-2][i] = c;
        }
        linecount++;
      }
    }
  }

  in_file.close();

  return initialGen;
}

/*
writeFile function
Write to file function which opens and declares the out_file. Mainly used
to ensure that it opens properly.
@param string outputFile - Name of file we are outputting to
@return ofstream out_file - The file which we are outputting to
*/
ofstream FileProcessor::writeFile(string outputFile){
  ofstream out_file;

  out_file.open(outputFile);
  if (!out_file.is_open()) {
     cout << "Could not open file " << outputFile << endl;
  }

  return out_file;
}

/*
getRows function
Getter method - Returns the number of rows of initialGen read from the file
@return int arrRow - Number of rows of initialGen
*/
int FileProcessor::getRows(){
  return arrRow;
}

/*
getCols function
Getter method - Returns the number of cols of initialGen read from the file
@return int arrCol - The number of rows of initialGen 
*/
int FileProcessor::getCols(){
  return arrCol;
}
