/*
Kaitlyn Vetica
CPSC 350-03
Header file for FileProcessor class. Defines constructor, destructor,
readFile, writeFile, and getter methods.
*/

#include <string>
using namespace std;

class FileProcessor{
  int arrRow;
  int arrCol;
public:
  FileProcessor();
  ~FileProcessor();
  char** readFile(string inputFile);
  ofstream writeFile(string outputFile);
  int getRows();
  int getCols();
};
