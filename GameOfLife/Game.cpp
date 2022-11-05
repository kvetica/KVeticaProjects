/*
Kaitlyn Vetica
CPSC 350-03
Creates a Boards class using Boards.h
Instantiates constructor, destructor, setter methods,
simulate, compare, isEmpty, and various print methods used in simulate(). This class is
where our simulate() function is located - this function runs the majority of the game, and holds
much of the game's rules.
*/

// This set of #include lines are for the sleep() function
// Reference for this found in README file
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "Game.h"
#include "FileProcessor.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
Default constructor for Game class
*/
Game::Game(){
  int gameMode = 0;
  int pauseMode = 0;
  int printMode = 0;
  int boardRows = 0;
  int boardCols = 0;
  char** grid1;
  ofstream out_file;
}

/*
Destructor for Game class
*/
Game::~Game(){}

/*
setInitialBoard function
Setter method - Sets the initialBoard which is the initial generation of the game.
@param char** grid - multidimensional array grid which is the initial grid given by user
                  or random config
@param int rows - Number of rows of the initial board
@param int cols - Number of cols of the initial board
@return void - No return
*/
void Game::setInitialBoard(char** grid, int rows, int cols){
  grid1 = grid;
  boardRows = rows;
  boardCols = cols;
}

/*
setGameMode function
Setter method - Sets the mode of the game. Integer indicates the game mode:
0 - Classic, 1 - Doughnut, 2 - Mirror
@param int mode - Integer which indicates which game mode will be played
@return void - No return
*/
void Game::setGameMode(int mode){
  gameMode = mode;
}

/*
setPauseMode function
Setter method - Sets the pause mode which will be executed during the game. Either
pause briefly between generations, press enter to continue, or print to file.
Creates FileProcessor object if user selects print to file
@param int mode - Integer indicates which mode is used.
                  0 - pause briefly, 1 - press enter, 2 - print to file
@param string outputFile - Output file name for if user selects print to file
@return void - No return
*/
void Game::setPauseMode(int mode, string outputFile){
  pauseMode = mode;
  if(pauseMode == 2){
    cout << "Printing to file." << endl;
    FileProcessor f;
    out_file = f.writeFile(outputFile);
  }
}

/*
simulate function
Simulate function holds the rules of the game. This method references methods from
Boards (including creating Boards object) and functions from this class to run the simulate
function. This function will continue printing new generations of the game until
the generation is empty, or is stable (the last and current generations match)
@return void - No return
*/
void Game::simulate(){
  Boards b;
  b.makeBoard(boardRows, boardCols, grid1);
  int keepGoing = 0;
  int genCount = 0;
  // Prints the initial generation / initialBoard
  printMethod("Gen " + to_string(genCount) + "\n");
  cin.get();
  printBoard(b.getCurrBoard());
  genCount++;

  // While the board is not stable
  while(keepGoing != 1){
    printPause();
    b.pad(gameMode);
    b.nextGeneration();
    printMethod("Gen " + to_string(genCount) + "\n");
    printBoard(b.getNextBoard());
    // If the board is empty, break from while loop. Generation is over
    if(isEmpty(b.getNextBoard())){
      break;
    }
    keepGoing = compare(b.getCurrBoard(), b.getNextBoard());
    b.flip();
    genCount++;
  }
    // Empty generation
    if(isEmpty(b.getNextBoard()) == 1){
      printMethod("World empty\n");
    }
    // Stable generation
    else{
      printMethod("Stability Achieved\n");
    }
    // Not printing to file mode
    if(pauseMode != 2){
      cout << "Press ENTER to exit." << endl;
      string exit;
      exit = cin.get();
      while(true){
        if(exit == "\n")
          break;
        exit = cin.get();
      }
    }
    // Printing to file mode
    else{
      cout << "Done printing to file." << endl;
      out_file.close();
    }
}

/*
compare function
Compares two boards and tells whether or not they are the exact same. If they are the same,
the method returns 1. If they are not the same, the method returns 0.
@param char** board1 - First board, multidimensional array, which is compared in this function
@param char** board2 - Second board, multidimensional array, which is compared in this function
@return int 0 or 1 - Returns 1 for same, 0 for different
*/
int Game::compare(char** board1, char** board2){
  for(int i = 0; i < boardRows; i++){
    for(int j = 0; j < boardCols; j++){
      if(board1[i][j] != board2[i][j]){
        return 0;
      }
    }
  }
  return 1;
}

/*
isEmpty function
This function tells whether or not the board is empty. The board is empty when all
spots within the grid are '-'. If the board is not empty, it will return 0. If the board is empty,
it will return 1.
@param char** board - multidimensional array, board, which is being tested if it is empty
@return int 0 or 1 - Returns 1 for empty, returns 0 for not empty.
*/
int Game::isEmpty(char** board){
  for(int i = 0; i < boardRows; i++){
    for(int j = 0; j < boardCols; j++){
      if(board[i][j] != '-'){
        return 0;
      }
    }
  }
  return 1;
}

/*
printBoard function
Print function which prints out the entire board/grid. Will process through multidimensional
array to print out each element as a grid. Prints to file if user asked to output to file.
@param char** board - Board which is being printed
@return void - No return
*/
void Game::printBoard(char** board){
  for(int i = 0; i < boardRows; i++){
    for(int j = 0; j < boardCols; j++){
      // If user did not ask to print to file
      if(pauseMode != 2)
        cout << board[i][j];
      // If user asked to print to file
      else
        out_file << board[i][j];
    }
    printMethod("\n");
  }
}

/*
printPause method
Pause method which dictates how the game "pauses" between generations. Will either pause
briefly or ask user to press ENTER to continue.
@return void - No return
*/
void Game::printPause(){
  // Pauses briefly
  if(pauseMode == 0){
    sleep(2);
  }
  // Press enter to continue
  else if(pauseMode == 1){
    string cont;
    cout << "Press ENTER to continue." << endl;
    cont = cin.get();
    while (true) {
      if(cont == "\n")
        break;
      cont = cin.get();
    }
  }
}

/*
printMethod function
Print method which decides where the information - the string - will be printed to.
If the user previously asked to print to file, it will print the string to output file.
Otherwise, will print to console.
@param string line - String which is being printed to either console or file
@return void - No return 
*/
void Game::printMethod(string line){
  if(pauseMode != 2){
    cout << line;
  }
  else{
    out_file << line;
  }
}
