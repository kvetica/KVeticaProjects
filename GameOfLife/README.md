# Game of Life
What is Game of Life?: https://playgameoflife.com/

Program determines future generations based on how the current one is filled, until the world is empty and the generation can no longer continue (either when the world is empty or stability is achieved in which the next generations are identical to the current one and no changes can be made). Initial generation can be generated from file input (example given in file in.txt) or from random generation based on user console input. Program will prompt user for information on how the program will generate the new generations and how the game will be played. 

Output can be generated to console or can be output to a file (example given in file exampleoutput.txt, using in.txt as the input).

## Identifying Information

* Name: Kaitlyn Vetica
* Email: kaitlynvgolf@gmail.com
* Course: CPSC 350 - Data Structures
* Assignment: Game of Life

## Source Files

* Game.cpp
* Boards.cpp
* FileProcessor.cpp
* mainprogram.cpp

## References

* cplusplus.com for multidimensional array and other function implementation
* www.softwaretestinghelp.com/cpp-sleep/ for sleep() function implementation, replacement for recommended
*           system("pause") function - pause function was not working on my terminal
*           Also used for solving Undefined Reference errors

## Known Errors

* Produces error when percentage is entered as a decimal. When prompted for percentage filled, enter as whole number (i.e. 35, 25, 50).

## Build Insructions

* <code> g++ -std=c++11 *.cpp -o out.o </code>

## Execution Instructions

* <code> ./out.o
* Enter user input accordingly when prompted. Percentage filled should be entered as a whole number integer not a decimal number. 
* User must Ctrl+C to exit program if generation creation is infinite and looping. Otherwise, program terminates by itself when generations can no longer continue (World Empty or Stability Achieved).

