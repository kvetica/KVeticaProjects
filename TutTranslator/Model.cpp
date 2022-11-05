/*
Kaitlyn Vetica
CPSC 350-03
Creates a Model class using Model.h
Instantiates constructor, destructor, translateSingleletteracter,
and translateDoubleletteracter
*/

#include "Model.h"
#include <iostream>
#include <string>
using namespace std;

/*
Default constructor for Model
*/
Model::Model(){}

/*
Destructor for Model
*/
Model::~Model(){}

/*
translateSingleCharacter function
Takes one character which is an English letter and
translates it to the accurate Tutnese translation. If it is a delimiter,
it will not translate it and return it as it is.
@param char letter - English letter to translate to Tutnese
@return string translatedChar - returns the string Tutnese translation of the char letter
*/
string Model::translateSingleCharacter(char letter){
  string translatedChar = "";
  if(isalpha(letter)){
    if(isupper(letter)){
      if(letter == 'B'){
        translatedChar = "Bub";
        return translatedChar;
      }
      else if(letter == 'C'){
        translatedChar = "Cash";
        return translatedChar;
      }
      else if(letter == 'D'){
        translatedChar = "Dud";
        return translatedChar;
      }
      else if(letter == 'F'){
        translatedChar = "Fuf";
        return translatedChar;
      }
      else if(letter == 'G'){
        translatedChar = "Gug";
        return translatedChar;
      }
      else if(letter == 'H'){
        translatedChar = "Hash";
        return translatedChar;
      }
      else if(letter == 'J'){
        translatedChar = "Jay";
        return translatedChar;
      }
      else if(letter == 'K'){
        translatedChar = "Kuck";
        return translatedChar;
      }
      else if(letter == 'L'){
        translatedChar = "Lul";
        return translatedChar;
      }
      else if(letter == 'M'){
        translatedChar = "Mum";
        return translatedChar;
      }
      else if(letter == 'N'){
        translatedChar = "Nun";
        return translatedChar;
      }
      else if(letter == 'P'){
        translatedChar = "Pub";
        return translatedChar;
      }
      else if(letter == 'Q'){
        translatedChar = "Quack";
        return translatedChar;
      }
      else if(letter == 'R'){
        translatedChar = "Rug";
        return translatedChar;
      }
      else if(letter == 'S'){
        translatedChar = "Sus";
        return translatedChar;
      }
      else if(letter == 'T'){
        translatedChar = "Tut";
        return translatedChar;
      }
      else if(letter == 'V'){
        translatedChar = "Vuv";
        return translatedChar;
      }
      else if(letter == 'W'){
        translatedChar = "Wack";
        return translatedChar;
      }
      else if(letter == 'X'){
        translatedChar = "Ex";
        return translatedChar;
      }
      else if(letter == 'Y'){
        translatedChar = "Yub";
        return translatedChar;
      }
      else if(letter == 'Z'){
        translatedChar = "Zub";
        return translatedChar;
      }
      else if(letter == 'A'){
        translatedChar = "A";
        return translatedChar;
      }
      else if(letter == 'E'){
        translatedChar = "E";
        return translatedChar;
      }
      else if(letter == 'I'){
        translatedChar = "I";
        return translatedChar;
      }
      else if(letter == 'O'){
        translatedChar = "O";
        return translatedChar;
      }
      else if(letter == 'U'){
        translatedChar = "U";
        return translatedChar;
      }
    }
    else if(islower(letter)){
      if(letter == 'b'){
        translatedChar = "bub";
        return translatedChar;
      }
      else if(letter == 'c'){
        translatedChar = "cash";
        return translatedChar;
      }
      else if(letter == 'd'){
        translatedChar = "dud";
        return translatedChar;
      }
      else if(letter == 'f'){
        translatedChar = "fuf";
        return translatedChar;
      }
      else if(letter == 'g'){
        translatedChar = "gug";
        return translatedChar;
      }
      else if(letter == 'h'){
        translatedChar = "hash";
        return translatedChar;
      }
      else if(letter == 'j'){
        translatedChar = "jay";
        return translatedChar;
      }
      else if(letter == 'k'){
        translatedChar = "kuck";
        return translatedChar;
      }
      else if(letter == 'l'){
        translatedChar = "lul";
        return translatedChar;
      }
      else if(letter == 'm'){
        translatedChar = "mum";
        return translatedChar;
      }
      else if(letter == 'n'){
        translatedChar = "nun";
        return translatedChar;
      }
      else if(letter == 'p'){
        translatedChar = "pub";
        return translatedChar;
      }
      else if(letter == 'q'){
        translatedChar = "quack";
        return translatedChar;
      }
      else if(letter == 'r'){
        translatedChar = "rug";
        return translatedChar;
      }
      else if(letter == 's'){
        translatedChar = "sus";
        return translatedChar;
      }
      else if(letter == 't'){
        translatedChar = "tut";
        return translatedChar;
      }
      else if(letter == 'v'){
        translatedChar = "vuv";
        return translatedChar;
      }
      else if(letter == 'w'){
        translatedChar = "wack";
        return translatedChar;
      }
      else if(letter == 'x'){
        translatedChar = "ex";
        return translatedChar;
      }
      else if(letter == 'y'){
        translatedChar = "yub";
        return translatedChar;
      }
      else if(letter == 'z'){
        translatedChar = "zub";
        return translatedChar;
      }
      else if(letter == 'a'){
        translatedChar = "a";
        return translatedChar;
      }
      else if(letter == 'e'){
        translatedChar = "e";
        return translatedChar;
      }
      else if(letter == 'i'){
        translatedChar = "i";
        return translatedChar;
      }
      else if(letter == 'o'){
        translatedChar = "o";
        return translatedChar;
      }
      else if(letter == 'u'){
        translatedChar = "u";
        return translatedChar;
      }
    }
  }
  else{
    translatedChar = letter;
    //cout << translatedChar << endl;
    return translatedChar;
  }
}

/*
translateDoubleCharacter function
Takes one English letter as a char and translates it to its "double character" translation in
Tutnese. Double character is whenever there is a double consonant or vowel.
Double consonant translates to "squa"+Tut translation of the consonant.
Double vowel translates to "squat"+vowel
@param char letter - English letter to translate to Tut double character translation
@return string translatedDoubleChar - Tut translation of English letter
*/
string Model::translateDoubleCharacter(char letter){
  string translatedDoubleChar = "";
  if(isupper(letter)){
    if(letter == 'B'){
      translatedDoubleChar = "Squabub";
      return translatedDoubleChar;
    }
    else if(letter == 'C'){
      translatedDoubleChar = "Squacash";
      return translatedDoubleChar;
    }
    else if(letter == 'D'){
      translatedDoubleChar = "Squadud";
      return translatedDoubleChar;
    }
    else if(letter == 'F'){
      translatedDoubleChar = "Squafuf";
      return translatedDoubleChar;
    }
    else if(letter == 'G'){
      translatedDoubleChar = "Squagug";
      return translatedDoubleChar;
    }
    else if(letter == 'H'){
      translatedDoubleChar = "Squahash";
      return translatedDoubleChar;
    }
    else if(letter == 'J'){
      translatedDoubleChar = "Squajay";
      return translatedDoubleChar;
    }
    else if(letter == 'K'){
      translatedDoubleChar = "Squakuck";
      return translatedDoubleChar;
    }
    else if(letter == 'L'){
      translatedDoubleChar = "Squalul";
      return translatedDoubleChar;
    }
    else if(letter == 'M'){
      translatedDoubleChar = "Squamum";
      return translatedDoubleChar;
    }
    else if(letter == 'N'){
      translatedDoubleChar = "Squanun";
      return translatedDoubleChar;
    }
    else if(letter == 'P'){
      translatedDoubleChar = "Squapub";
      return translatedDoubleChar;
    }
    else if(letter == 'Q'){
      translatedDoubleChar = "Squaquack";
      return translatedDoubleChar;
    }
    else if(letter == 'R'){
      translatedDoubleChar = "Squarug";
      return translatedDoubleChar;
    }
    else if(letter == 'S'){
      translatedDoubleChar = "Squasus";
      return translatedDoubleChar;
    }
    else if(letter == 'T'){
      translatedDoubleChar = "Squatut";
      return translatedDoubleChar;
    }
    else if(letter == 'V'){
      translatedDoubleChar = "Squavuv";
      return translatedDoubleChar;
    }
    else if(letter == 'W'){
      translatedDoubleChar = "Squawack";
      return translatedDoubleChar;
    }
    else if(letter == 'X'){
      translatedDoubleChar = "Squaex";
      return translatedDoubleChar;
    }
    else if(letter == 'Y'){
      translatedDoubleChar = "Squayub";
      return translatedDoubleChar;
    }
    else if(letter == 'Z'){
      translatedDoubleChar = "Squazub";
      return translatedDoubleChar;
    }
    else if(letter == 'A'){
      translatedDoubleChar = "Squata";
      return translatedDoubleChar;
    }
    else if(letter == 'E'){
      translatedDoubleChar = "Squate";
      return translatedDoubleChar;
    }
    else if(letter == 'I'){
      translatedDoubleChar = "Squati";
      return translatedDoubleChar;
    }
    else if(letter == 'O'){
      translatedDoubleChar = "Squato";
      return translatedDoubleChar;
    }
    else if(letter == 'U'){
      translatedDoubleChar = "Squatu";
      return translatedDoubleChar;
    }
  }
  else if(islower(letter)){
    if(letter == 'b'){
      translatedDoubleChar = "squabub";
      return translatedDoubleChar;
    }
    else if(letter == 'c'){
      translatedDoubleChar = "squacash";
      return translatedDoubleChar;
    }
    else if(letter == 'd'){
      translatedDoubleChar = "squadud";
      return translatedDoubleChar;
    }
    else if(letter == 'f'){
      translatedDoubleChar = "squafuf";
      return translatedDoubleChar;
    }
    else if(letter == 'g'){
      translatedDoubleChar = "squagug";
      return translatedDoubleChar;
    }
    else if(letter == 'h'){
      translatedDoubleChar = "squahash";
      return translatedDoubleChar;
    }
    else if(letter == 'j'){
      translatedDoubleChar = "squajay";
      return translatedDoubleChar;
    }
    else if(letter == 'k'){
      translatedDoubleChar = "squakuck";
      return translatedDoubleChar;
    }
    else if(letter == 'l'){
      translatedDoubleChar = "squalul";
      return translatedDoubleChar;
    }
    else if(letter == 'm'){
      translatedDoubleChar = "squamum";
      return translatedDoubleChar;
    }
    else if(letter == 'n'){
      translatedDoubleChar = "squanun";
      return translatedDoubleChar;
    }
    else if(letter == 'p'){
      translatedDoubleChar = "squapub";
      return translatedDoubleChar;
    }
    else if(letter == 'q'){
      translatedDoubleChar = "squaquack";
      return translatedDoubleChar;
    }
    else if(letter == 'r'){
      translatedDoubleChar = "squarug";
      return translatedDoubleChar;
    }
    else if(letter == 's'){
      translatedDoubleChar = "squasus";
      return translatedDoubleChar;
    }
    else if(letter == 't'){
      translatedDoubleChar = "squatut";
      return translatedDoubleChar;
    }
    else if(letter == 'v'){
      translatedDoubleChar = "squavuv";
      return translatedDoubleChar;
    }
    else if(letter == 'w'){
      translatedDoubleChar = "squawack";
      return translatedDoubleChar;
    }
    else if(letter == 'x'){
      translatedDoubleChar = "squaex";
      return translatedDoubleChar;
    }
    else if(letter == 'y'){
      translatedDoubleChar = "squayub";
      return translatedDoubleChar;
    }
    else if(letter == 'z'){
      translatedDoubleChar = "squazub";
      return translatedDoubleChar;
    }
    else if(letter == 'a'){
      translatedDoubleChar = "squata";
      return translatedDoubleChar;
    }
    else if(letter == 'e'){
      translatedDoubleChar = "squate";
      return translatedDoubleChar;
    }
    else if(letter == 'i'){
      translatedDoubleChar = "squati";
      return translatedDoubleChar;
    }
    else if(letter == 'o'){
      translatedDoubleChar = "squato";
      return translatedDoubleChar;
    }
    else if(letter == 'u'){
      translatedDoubleChar = "squatu";
      return translatedDoubleChar;
    }
  }
}
