/*
Kaitlyn Vetica
CPSC 350-03
Creates a Boards class using Boards.h
Instantiates constructor, destructor, and all other classes previously declared in Boards.h.
This class' main role is creating the boards which are swapped back and forth in generation of
new life generations. This class can also perform random() which randomly builds a
configuration based on user input.
*/

#include "Boards.h"
#include <iostream>
#include <string>
using namespace std;

/*
Default constructor for Boards
*/
Boards::Boards(){
  char** currBoard;
  char** nextBoard;
  char** paddedBoard;
  int boardRows;
  int boardCols;
}

/*
Destructor for Boards
*/
Boards::~Boards(){}

/*
makeBoard function
Instantiates the double array pointers for currBoard and nextBoard which are the arrays
used as our boards for the game of life. currBoard points to the same values as paramater
char** b
@param int rows - The number of rows in the multidimensional array, b
@param int cols - The number of cols in the multidimensional array, b
@param char** b - char pointer which points to multidimensional array b
@return void - No return
*/
void Boards::makeBoard(int rows, int cols, char** b){
  currBoard = b;
  nextBoard = new char*[rows];
  for(int i = 0; i < rows; i++){
    nextBoard[i] = new char[cols];
  }
  boardRows = rows;
  boardCols = cols;
}

/*
pad function
Creates a new multidimensional array that is the same as currBoard, but has a boarder
around it which is our boundary used in the game. Based upon what game mode we are in,
the boundaries are filled with either '-' or 'X'
@param int gameMode - The game mode which we are in. Dictates how boundaries are filled.
                Int indicates the game mode - Classic, doughnut, or mirror mode.
@return void - No return
*/
void Boards::pad(int gameMode){
  paddedBoard = new char*[boardRows+2];

  for(int i = 0; i < boardRows+2; i++){
    paddedBoard[i] = new char[boardCols+2];
  }

  for(int i = 0; i < boardRows; i++){
    for(int j = 0; j < boardCols; j++){
      paddedBoard[i+1][j+1] = currBoard[i][j];
    }
  }

  // classic mode = 0
  if(gameMode == 0){
    for(int i = 0; i < boardRows+2; i++){
      for(int j = 0; j < boardCols+2; j++){
        if(i == 0 || j == 0 || i == boardRows+1 || j == boardCols + 1){
          paddedBoard[i][j] = '-';
        }
      }
    }
  }

  // doughnut mode = 1
  else if(gameMode == 1){
    for(int i = 0; i < boardRows+2; i++){
      for(int j = 0; j < boardCols+2; j++){
        if(i == 0){
          if(j != 0 && j != boardCols+1)
            paddedBoard[i][j] = paddedBoard[boardRows][j];
          else if(j == 0)
            paddedBoard[i][j] = paddedBoard[boardRows][boardCols];
          else
            paddedBoard[i][j] = paddedBoard[boardRows][1];
        }
        else if(i == boardRows+1){
          if(j != 0 && j != boardCols+1)
            paddedBoard[i][j] = paddedBoard[1][j];
          else if(j == 0)
            paddedBoard[i][j] = paddedBoard[1][boardCols];
          else
            paddedBoard[i][j] = paddedBoard[1][1];
        }
        else if(j == 0){
          if(i > 0 && i < boardRows+1)
            paddedBoard[i][j] = paddedBoard[i][boardCols];
        }
        else if(j == boardCols+1){
          if(i > 0 && i < boardRows+1)
            paddedBoard[i][j] = paddedBoard[i][1];
        }
      }
    }
  }

  // mirror mode = 2
  else if(gameMode == 2){
    for(int i = 0; i < boardRows+2; i++){
      for(int j = 0; j < boardCols+2; j++){
        if(i == 0){
          if(j != 0 && j != boardCols+1)
            paddedBoard[i][j] = paddedBoard[1][j];
          else if(j == 0)
            paddedBoard[i][j] = paddedBoard[1][1];
          else
            paddedBoard[i][j] = paddedBoard[1][boardCols];
        }
        else if(i == boardRows+1){
          if(j != 0 && j != boardCols+1)
            paddedBoard[i][j] = paddedBoard[boardRows][j];
          else if(j == 0)
            paddedBoard[i][j] = paddedBoard[boardRows][1];
          else
            paddedBoard[i][j] = paddedBoard[boardRows][boardCols];
        }
        else if(j == 0){
          if(i != 0 && i != boardRows+1)
            paddedBoard[i][j] = paddedBoard[i][1];
        }
        else if(j == boardCols+1){
          if(i != 0 && i != boardRows+1)
            paddedBoard[i][j] = paddedBoard[i][boardCols];
        }
      }
    }
  }
}

/*
flip function
Swaps the two pointers for currBoard and nextBoard so we are swapping back and forth
between the two grids during the simulation so we do not create a new grid every time.
@return void - No return
*/
void Boards::flip(){
  char** temp = currBoard;
  currBoard = nextBoard;
  nextBoard = temp;
}

/*
getCurrBoard function
Getter method - returns the currBoard
@return char** currBoard - the currBoard which is the current board being looked at
*/
char** Boards::getCurrBoard(){
  return currBoard;
}

/*
getPaddedBoard function
Getter method - returns the paddedBoard
@return char** paddedBoard - the paddedBoard which is the board which we previously padded with boundaries
*/
char** Boards::getPaddedBoard(){
  return paddedBoard;
}

/*
getNextBoard function
Getter method - returns the nextBoard
@return char** nextBoard - the nextBoard which is the board we fill during simulation
*/
char** Boards::getNextBoard(){
  return nextBoard;
}

/*
nextGeneration function
Looks at currBoard and dictates what the next generation (nextBoard) will look like based on the
following rules:
- Location with one or fewer neighbors will be empty next gen
- Location with 2 neighbors will remain stable in next gen
- Location with 3 neighbors will contain a cell in next gen
- Location with 4 or more neighbors will be empty next gen
@return void - No return 
*/
void Boards::nextGeneration(){
  for(int i = 1; i < boardRows+1; i++){
    for(int j = 1; j < boardCols+1; j++){
      int neighbors = 0;
      if(paddedBoard[i-1][j-1] == 'X')
        neighbors++;
      if(paddedBoard[i-1][j] == 'X')
        neighbors++;
      if(paddedBoard[i-1][j+1] == 'X')
        neighbors++;
      if(paddedBoard[i][j-1] == 'X')
        neighbors++;
      if(paddedBoard[i][j+1] == 'X')
        neighbors++;
      if(paddedBoard[i+1][j-1] == 'X')
        neighbors++;
      if(paddedBoard[i+1][j] == 'X')
        neighbors++;
      if(paddedBoard[i+1][j+1] == 'X')
        neighbors++;

      if(neighbors <= 1)
        nextBoard[i-1][j-1] = '-';
      else if(neighbors == 2)
        nextBoard[i-1][j-1] = currBoard[i-1][j-1];
      else if(neighbors == 3)
        nextBoard[i-1][j-1] = 'X';
      else if(neighbors >= 4)
        nextBoard[i-1][j-1] = '-';

    }
  }
}

/*
random function
Randomly fills a multidimensional array, randBoard, based on user inputted percentage of filled
locations, and rows and columns. Based on percentage, will fill the board randomly.
@param double percent - User inputted percentage of how many locations will be filled
@param int rows - User inputted number of rows of the board
@param int cols - User inputted number of cols of the board
@return char** randBoard - Returns the random board generated in this function
*/
char** Boards::random(double percent, int rows, int cols){
  char** randBoard = new char*[rows];
  for(int i = 0; i < rows; i++){
    randBoard[i] = new char[cols];
  }

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      randBoard[i][j] = '-';
    }
  }

  double temp = percent / 100;
  int mult = rows * cols;
  int filled = (int)(temp * mult);

  while(filled > 0){
    int randRow = rand() % rows;
    int randCol = rand() % cols;
    if(randBoard[randRow][randCol] != 'X'){
      randBoard[randRow][randCol] = 'X';
      filled--;
    }
  }
  return randBoard;
}
