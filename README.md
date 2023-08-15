# Sudoku Solver in C++
C++ implementation of a Sudoku Solver. It provides functionalities to read a Sudoku puzzle from a file, check if the puzzle is solvable, solve the puzzle, and display the solved puzzle.

## Features

### Sudoku Namespace
- **`Location` Structure**: Defines a location within the Sudoku grid with row and column coordinates.

### SudokuSolver Class
- **Constructor**: Initialize a new Sudoku Solver object, either empty or by reading from a file.
- **Solvability Check**: Checks if the given puzzle is solvable.
- **Get and Set Puzzle Numbers**: Access or modify the puzzle numbers.
- **Display Function**: Prints the current state of the puzzle.
- **Legal Value Check**: Checks if a given value is legal in a specified location in the grid.
- **Solve Function**: Attempts to solve the Sudoku puzzle.

## Public Methods
- `SudokuSolver()`: Default constructor.
- `SudokuSolver(std::string filename)`: Constructor with a filename for reading the puzzle.
- `bool isPuzzleSolvable()`: Returns whether the puzzle is solvable.
- `int** getPuzzleNumbers()`: Returns the puzzle numbers.
- `void display()`: Displays the puzzle.
- `void setSolvable()`: Sets the solvable status of the puzzle.
- `int** getPuzzleNumber()`: Gets the puzzle number (seems like a typo or duplicate).
- `void setPuzzleNumbers(int** puzzle)`: Sets the puzzle numbers.
- `Sudoku::Location returnNextEmpty()`: Returns the next empty location in the puzzle.
- `bool checkLegalValue(int Number, Sudoku::Location loc)`: Checks if a number is legal at a given location.
- `bool solve()`: Solves the Sudoku puzzle.

## Private Members
- `int** SudokuPuzzle_`: 2D array representing the Sudoku grid.
- `bool solvable_`: Boolean flag indicating if the puzzle is solvable.

## Usage

```cpp
#include "SudokuSolver.hpp"

int main() {
    SudokuSolver solver("puzzle.txt");
    if (solver.isPuzzleSolvable()) {
        solver.solve();
        solver.display();
    } else {
        std::cout << "The puzzle is not solvable!" << std::endl;
    }
}
```
# License
This project is open-source and available under the MIT License.
