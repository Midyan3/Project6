/***
 * SudokuSolver.hpp
 * Author: Midyan Elghazali
 * professor: ligaro
 * Date: May 2 2021
 * 
*/
#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_
#include <iostream>
#include <fstream>
#include <sstream>
//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
namespace Sudoku
{ 
  struct Location
  {
    int row;
    int col;
  };
}

class SudokuSolver
{
public:
/**
 * @brief Construct a new Sudoku Solver object
 * 
 */
SudokuSolver();
/**
 * @brief Construct a new Sudoku Solver object
 * 
 * @param filename 
 */
SudokuSolver(std::string filename);
/**
 * @brief returns is the puzzle solvable
 * 
 * @return true 
 * @return false 
 */
bool isPuzzleSolvable(); 
/**
 * @brief Get the Puzzle Numbers object
 * 
 * @return int** 
 */

int** getPuzzleNumbers();
/**
 * @brief display the puzzle
 * 
 */
void display();
/**
 * @brief Set the Solvable object
 * 
 */
void setSolvable();
//Add your public members here
/**
 * @brief Get the Puzzle Number object
 * 
 * @return int** 
 */
int** getPuzzleNumber();
/**
 * @brief Set the Puzzle Numbers object
 * 
 * @param puzzle 
 */
void setPuzzleNumbers(int** puzzle);
/**
 * @brief Gets the next empty location in the puzzle
 * 
 * @return Sudoku::Location 
 */
Sudoku::Location returnNextEmpty();
/**
 * @brief Checks if the value is legal in the row
 * 
 * @param Number 
 * @param loc 
 * @return true 
 * @return false 
 */
bool checkLegalValue(int Number, Sudoku::Location loc);
/**
 * @brief Sloves the Sudoku puzzle
 * 
 * @return true 
 * @return false 
 */
bool solve();


private:
//Add your private members here
int** SudokuPuzzle_;
bool solvable_;






};

#endif
