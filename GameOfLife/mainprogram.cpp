/*
Kaitlyn Vetica
CPSC 350-03
Mainprogram for Game of Life. Runs all needed methods from the Game classes
to execute generation simulation (simulate() method from Game class) for Game of Life.
Prompts user for how they want to generate the initial world, what game mode to run,
what kind of "pause" there will be between generation or if they want to print to a file,
and the size of the array.
*/

#include "FileProcessor.h"
#include "Game.h"
#include <iostream>
using namespace std;

/*
main function
Our main function which runs the Game of Life. Uses Game, Boards, and FileProcessor
objects to properly execute the Game of Life and execute methods from those classes.
@return int - Returns 0 when completed 
*/
int main(){
  FileProcessor f;
  string inFile = "";
  string outFile = "";
  int userChoice = 0;
  int modeChoice = 0;
  int pauseChoice = 0;
  char** initialGrid;
  int gridRows = 0;
  int gridCols = 0;

  Game g;
  Boards b;

  cout << "Enter 1 for random generation, 2 for input file: ";
  cin >> userChoice;

  // Random generation configuration
  if(userChoice == 1){
    double randPercent = 0;
    int row, col;
    cout << "Enter percentage (without %) that should be filled in generation: ";
    cin >> randPercent;
    cout << "Enter row size: ";
    cin >> row;
    cout << "Enter column size: ";
    cin >> col;
    initialGrid = b.random(randPercent, row, col);
    g.setInitialBoard(initialGrid, row, col);
  }
  // File input configuration
  else if(userChoice == 2){
    cout << "Enter input file name: ";
    cin >> inFile;
    initialGrid = f.readFile(inFile);
    gridRows = f.getRows();
    gridCols = f.getCols();
    g.setInitialBoard(initialGrid, gridRows, gridCols);
  }
  // Neither 1 or 2 inputted
  else{
    cout << "Invalid selection" << endl;
  }

  // Game mode selection
  cout << "What game mode? Enter: 0-Classic, 1-Doughnut, 2-Mirror: ";
  cin >> modeChoice;

  // Pause selection
  cout << "How would you like to pause between generations?" << endl;
  cout << "Enter: 0-Brief pause, 1-Press enter to continue, 2-Ouput to file: ";
  cin >> pauseChoice;
  string outputFile;

  // File output selection
  if(pauseChoice == 2){
    cout << "Enter output file name: ";
    cin >> outputFile;
  }

  g.setGameMode(modeChoice);
  g.setPauseMode(pauseChoice, outputFile);
  g.simulate();


  return 0;
}
