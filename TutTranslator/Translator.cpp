/*
Kaitlyn Vetica
CPSC 350-03
Creates a Translator class using Translator.h
Instantiates constructor, destructor, translateEnglishWord,
and translateEnglishSentence
*/

#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <string>
using namespace std;

/*
Default constructor for Translator
*/
Translator::Translator(){}

/*
Destructor for Translator
*/
Translator::~Translator(){}

/*
translateEnglishWord function
Translates full English word (string word) to Tutnese translation, using translateSingleCharacter
and translateDoubleCharacter functions to do so.
@param string word - English word to translate to Tutnese
@return string translatedWord - Tutnese translation of the English word parameter
*/
string Translator::translateEnglishWord(string word){
  Model model;
  string translatedWord = "";
  for(int i = 0; i <= word.size(); i++){
    if(word[i] == (word[i+1])){
      translatedWord += (model.translateDoubleCharacter(word[i]));
      i++;
    }
    else{
      translatedWord += (model.translateSingleCharacter(word[i]));
    }
  }
  //cout << translatedWord << endl;
  return translatedWord;
}

/*
translateEnglishSentence function
Translates full English sentence to Tutnese translation using translateEnglishWord
function implemented in this class.
@param string sent - Shorthand for "sentence." English sentence to be translated to Tutnese
@return string fullSent - Shorthand for "full sentence." Returned Tutnese translation of the
                original English sentence.
*/
string Translator::translateEnglishSentence(string sent){
  string word = "";
  string fullSent = "";
  string translatedSent = "";
  //cout << "1" << endl;
  for(int i = 0; i <= sent.size(); i++){
    if(isalpha(sent[i]) && (sent[i] != '\n')){
      word += sent[i];
      //cout << sent[i] << endl;
    }
    else if(sent[i] == '\n'){
      i++;
      i++;
    }
    else{
      word += sent[i];
      //cout << "2" << endl;
      //cout << sent[i] << endl;
      translatedSent = translateEnglishWord(word);
      word = "";
      fullSent += translatedSent;
    }
  }
  //cout << fullSent << endl;
  return fullSent;
}
