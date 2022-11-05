/*
Kaitlyn Vetica
CPSC 350-03
Header file for FileProcessor class. Defines constructor, destructor,
and processFile.
*/

#include <string>
using namespace std;

class FileProcessor{
public:
  FileProcessor();
  ~FileProcessor();
  void processFile(string inputfile, string outputfile);
};
