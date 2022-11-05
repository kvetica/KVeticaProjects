/*
Kaitlyn Vetica
CPSC 350-03
Header file for Boards class. Defines constructor, destructor,
makeBoard, flip, pad, getter methods, nextGeneration, and random methods.
Declares private variables used in Boards class. 
*/

#include <string>
using namespace std;

class Boards{
  char** currBoard;
  char** nextBoard;
  char** paddedBoard;
  int boardRows;
  int boardCols;
public:
  Boards();
  ~Boards();
  void makeBoard(int rows, int cols, char** b);
  void pad(int gameMode);
  void flip();
  char** getCurrBoard();
  char** getPaddedBoard();
  char** getNextBoard();
  void nextGeneration();
  char** random(double percent, int rows, int cols);
};
