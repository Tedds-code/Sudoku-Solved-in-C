# Sudoku Solver in C

A command-line Sudoku solver written in C. It reads a 9×9 puzzle from a text file, validates it, solves it with recursive backtracking, and displays the solved grid in the terminal using `ncurses`.

Originally written as a university assignment.

## Features

- Reads a puzzle from a plain text file passed as a command-line argument
- Validates the input before solving:
  - exactly 9 rows and 81 cells
  - only the characters `0`–`9` (`0` = empty cell)
  - no duplicates in any row, column or 3×3 box
- Solves the puzzle with a backtracking algorithm
- Reports clear error messages for malformed or unsolvable puzzles
- Renders the finished grid as a bordered board using `ncurses`
- Dynamically allocated board, freed before exit

## Requirements

- A C compiler (e.g. `gcc`)
- The ncurses development library
  - Debian/Ubuntu: `sudo apt install libncurses-dev`
  - Fedora: `sudo dnf install ncurses-devel`
  - macOS (Homebrew): `brew install ncurses`

## Build

```bash
gcc Ergasia1.c -lncurses -o Ergasia1
```

## Usage

```bash
./Ergasia1 <puzzle-file>
```

Press any key to exit once the solution is displayed.

### Input format

Nine lines of nine characters each. Use `0` for an empty cell:

```
530070000
600195000
098000060
800060003
400803001
700020006
060000280
000419005
000080079
```

Example puzzles, including intentionally invalid ones, are in the `examples/` folder.

## How it works

1. **Parsing (`get_Sudoku`)**: reads the file character by character into a dynamically allocated 9×9 `char` matrix, ignoring newlines.
2. **Validation (`validate_Sudoku`)**: checks the dimensions and characters, then runs `validate_Rows`, `validate_Cols` and `validate_Box` on every filled cell.
3. **Solving (`solve_Sudoku`)**: finds the first empty cell, tries digits `1`–`9`, keeps those that pass the three validity checks, and recurses. If no digit fits, it backtracks to the previous cell and tries the next candidate. If every option is exhausted, the puzzle has no solution.
4. **Display (`present_Sudoku`)**: draws the grid with `ncurses` line-drawing and prints each cell.

## Possible improvements

- Faster solving by choosing the cell with the fewest candidates first, or by tracking used digits in bitmasks instead of rescanning
- Detecting puzzles with multiple solutions
- Splitting the code into separate source and header files

## Notes

Code comments are written in Greek.

## License

MIT
