/*
Kaitlyn Vetica
CPSC 350-03
Creates a FileProcessor class using FileProcessor.h
Instantiates constructor, destructor, and processFile
*/

#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>
#include <iostream>

/*
Default constructor for FileProcessor
*/
FileProcessor::FileProcessor(){}

/*
Destructor for FileProcessor
*/
FileProcessor::~FileProcessor(){}

/*
processFile function
Opens an "in_file" which holds the English text that we wish to translate.
Processes through the in_file and performs translation on the English text using
translateEnglishSentence from Translator class. Writes the translation to a new output
file, out_file. Closes both files at the end.
@param string inputName - The name of the file which is being read from, holds English text
@param string outputName - The name of the file which is being written onto, to hold Tutnese translation
@return void, no return
*/
void FileProcessor::processFile(string inputName, string outputName){
  ifstream in_file;
  ofstream out_file;
  string line;
  string userInput = "";

  in_file.open(inputName);
  if (!in_file.is_open()) {
     cout << "Could not open file " << inputName << endl;
  }

  //in_file >> userInput;

  Translator converter; // here you can use an object of the Translator class
  // for each line of the input file, call the Translator object's translateEnglishSentence function
  out_file.open(outputName);
  if (!out_file.is_open()) {
     cout << "Could not open file " << outputName << endl;
  }

  if(in_file.is_open()){
    //cout << "5" << endl;
    while(getline(in_file, line)){
      //cout << "3" << endl;
      string convertedSent = "";
      convertedSent = converter.translateEnglishSentence(line);
      out_file << convertedSent;
      //cout << convertedSent << endl;
    }
  }

  in_file.close();
  out_file.close();

}
