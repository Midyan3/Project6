#include "SudokuSolver.hpp"
/***
 * SudokuSolver.cpp
 * Author: Midyan Elghazali
 * professor: ligaro
 * Date: May 2 2021
 * 
*/

/**
 * @brief Construct a new Sudoku Solver:: Sudoku Solver object
 * 
 */
SudokuSolver::SudokuSolver(){
    SudokuPuzzle_ = new int*[9];
    for(int i = 0; i < 9; i++){
        SudokuPuzzle_[i] = new int[9];
        for(int j = 0; j < 9; j++){
            SudokuPuzzle_[i][j] = 0;
        }
    }
    
    solvable_ = false;
}
/**
 * @brief Construct a new Sudoku Solver:: Sudoku Solver object
 * 
 * @param filename 
 */
SudokuSolver::SudokuSolver(std::string filename){
    std::ifstream file;
    SudokuPuzzle_ = new int*[9];
    for(int i = 0; i < 9; i++){
        SudokuPuzzle_[i] = new int[9];
    } 
    file.open(filename);
    if(file.fail()){
        std::cout << "File not found" << std::endl;
        return;
    }
    std::string line;
    std::string cell;
    int row {0}, col {0};
    while (std::getline(file, line)) {
        std::stringstream line_stream(line);
        while (std::getline(line_stream, cell, ',')) {
            SudokuPuzzle_[row][col] = std::stoi(cell);
            col++;
        }
        row++;
        col = 0; 
    }
    solvable_ = solve();
}
/**
 * @brief Display the sudoku puzzle
 * 
 * @return void
 */
void SudokuSolver::display(){
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0 && i != 0){
            std::cout << "- - - - - - - - - - - - " << std::endl;
        }
        for(int j = 0; j < 9; j++){
            if(j % 3 == 0 && j != 0 && j != 8){
                std::cout << " | ";
            }
            if(j == 8){
                if(SudokuPuzzle_[i][j] == 0){
                    std::cout << "X";
                }
                else{
                    std::cout << SudokuPuzzle_[i][j];
                }
            }
            else{
                 if(SudokuPuzzle_[i][j] == 0){
                    std::cout << "X ";
                }
                else{
                    std::cout << SudokuPuzzle_[i][j]<< " ";
                }
            }
        }
        std::cout << std::endl;
    }
}
/**
 * @brief Set the Solvable object to true
 * 
 */
void SudokuSolver::setSolvable(){
    solvable_ = true;
}
/**
 * @brief Get the Puzzle Numbers object
 * 
 * @return int** 
 */
int** SudokuSolver::getPuzzleNumbers(){
    return SudokuPuzzle_;
}
/**
 * @brief Get the Puzzle Number object and sets it to the puzzle parameter
 * 
 * @param puzzle 
 */
void SudokuSolver::setPuzzleNumbers(int** puzzle){
    SudokuPuzzle_ = puzzle;
}
/**
 * @brief Get the solvable object
 * 
 * @return true 
 * @return false 
 */
bool SudokuSolver::isPuzzleSolvable(){
    return solvable_;
}
/**
 * @brief Gets the next empty location in the puzzle
 * 
 * @return Sudoku::Location 
 */
Sudoku::Location SudokuSolver::returnNextEmpty(){
    Sudoku::Location empty;
    empty.row = -1;
    empty.col = -1;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(SudokuPuzzle_[i][j] == 0){
                empty.row = i;
                empty.col = j;
                return empty;
            }
        }
    }
    return empty;
}
/**
 * @brief Checks if the value is legal in the puzzle
 * 
 * @param Number 
 * @param loc 
 * @return true 
 * @return false 
 */

bool SudokuSolver::checkLegalValue(int Number, Sudoku::Location loc){
    for(int i = 0; i < 9; i++){
        if(SudokuPuzzle_[loc.row][i] == Number){
            return false;
        }
    }
    for(int i = 0; i < 9; i++){
        if(SudokuPuzzle_[i][loc.col] == Number){
            return false;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){ 
            if(SudokuPuzzle_[i + (loc.row - loc.row % 3)][j + (loc.col - loc.col % 3)] == Number){
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Solves the puzzle
 * 
 * @return true 
 * @return false 
 */
bool SudokuSolver::solve(){
    Sudoku::Location empty = returnNextEmpty();
    if(empty.row == -1 && empty.col == -1){
        return true;
    }
    for(int i = 1; i < 10; i++){
        if(checkLegalValue(i, empty)){
            SudokuPuzzle_[empty.row][empty.col] = i;
            if(solve()){
                return true;
            }
        }
    }
    SudokuPuzzle_[empty.row][empty.col] = 0;
    return false;
}