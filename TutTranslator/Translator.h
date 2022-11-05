/*
Kaitlyn Vetica
CPSC 350-03
Header file for Translator class. Defines constructor, destructor, translateEnglishWord,
and translateEnglishSentence
*/

using namespace std;
#include <string>

class Translator{
public:
  Translator();
  ~Translator();
  string translateEnglishWord(string word);
  string translateEnglishSentence(string sent);
};
