/*
Kaitlyn Vetica
CPSC 350-03
Header file for Game class. Defines constructor, destructor, setter methods,
simulate, compare, isEmpty, and various print methods used in simulate(). Declares
private variables used in Game class.
*/

#include "Boards.h"
#include <string>
#include <fstream>
using namespace std;

class Game{
  int gameMode;
  int pauseMode;
  int boardRows;
  int boardCols;
  char** grid1;
  ofstream out_file;

public:
  Game();
  ~Game();
  void setInitialBoard(char** grid, int rows, int cols);
  void setGameMode(int mode);
  void setPauseMode(int mode, string outputFile);
  void simulate();
  int compare(char** board1, char** board2);
  int isEmpty(char** board);
  void printBoard(char** board);
  void printPause();
  void printMethod(string line);

};
