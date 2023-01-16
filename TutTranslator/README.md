# Tut Translator
Translates input file (written in English) to Tutnese.

What is Tutnese? https://en.wikipedia.org/wiki/Tutnese 

Translation rules that the program accounts for: 
* Every consonant has a 3 letter translation in tutnese associated with it. (These translations can be found on the wikipedia page or in Model.cpp from lines 36-140.)
* Vowels are kept the same (a, e, i, o, u)
* Double letters are replaced by the prefix 'squa-' and the according consonant translation. (i.e. 'll' is replaced by 'squalul').
* Punctuation is kept the same.

## Identifying Information

* Name: Kaitlyn Vetica
* Email: kaitlynvetica@gmail.com
* Course: CPSC 350 - Data Structures
* Date: Spring 2021
* Assignment: Tut Translator

## Source Files

* Model.cpp
* Translator.cpp
* FileProcessor.cpp
* mainprogram.cpp

## References

* cplusplus.com for string and fstream methods and implementation 

## Known Errors

* Cannot open files when .txt is not included in user input.

## Example Input and Output

* Given in files input.txt and exampleoutput.txt

## Build Insructions

* <code> g++ -std=c++11 *.cpp -o out.o </code>

## Execution Instructions

* <code> ./out.o </code>
* Enter file names including the .txt


