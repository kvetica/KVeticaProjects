/*
Kaitlyn Vetica
CPSC 350-03
Uses functions from FileProcessor class to process through text file of English
sentences/words and translates them to Tutnese using translator methods. Writes
to an output file of the new translation of the original input.
*/

#include "FileProcessor.h"
#include "Translator.h"
#include <iostream>
using namespace std;

/*
main function
Creates a FileProcessor object and uses it to process through an in file given
by user input, and writes to an output file also given by user input.
@return int 0 - Returns 0 at the end of the function 
*/
int main(){
  FileProcessor f;
  string inFile = "";
  string outFile = "";

  cout << "Enter input file name: ";
  cin >> inFile;
  cout << "Enter output file name: ";
  cin >> outFile;

  f.processFile(inFile,outFile);
  return 0;
}
