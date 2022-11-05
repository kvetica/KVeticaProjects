/*
Kaitlyn Vetica
CPSC 350-03
Header file for Model class. Defines constructor, destructor, translateSingleCharacter,
and translateDoubleCharacter
*/

#include <string>
using namespace std;

class Model{
public:
  Model();
  ~Model();
  string translateSingleCharacter(char letter);
  string translateDoubleCharacter(char letter);
};
