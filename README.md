Sudoku Solver using Backtracking

Overview

This project implements a Sudoku Solver using the Backtracking Algorithm in C++. The solver takes an incomplete Sudoku grid as input and finds a solution by filling in the missing numbers while ensuring all Sudoku rules are met.

Sudoku Rules

Each row must contain numbers from 1 to 9 without repetition.

Each column must contain numbers from 1 to 9 without repetition.

Each 3×3 subgrid must contain numbers from 1 to 9 without repetition.

Algorithm Explanation

The backtracking algorithm follows these steps:

Find an empty cell in the Sudoku grid.

Try placing a number (1-9) in the empty cell.

Check if the number placement follows Sudoku rules.

If valid, recursively attempt to solve the remaining grid.

If a conflict occurs, backtrack and try the next possible number.

Repeat until the grid is completely filled.

Code Structure

sudoku_solver.cpp → Implements the backtracking algorithm.

input.txt (optional) → Contains test Sudoku puzzles.

README.md → Documentation for the project.

How to Run

Compilation

Use a C++ compiler (e.g., g++) to compile the code:

 g++ sudoku_solver.cpp -o sudoku_solver

Execution

Run the executable:

 ./sudoku_solver

Sample Input (Sudoku Grid)

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

Sample Output (Solved Sudoku)

5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9

Complexity Analysis

The worst-case time complexity is O(9^N), where N is the number of empty cells.

The average-case complexity is much lower due to pruning by Sudoku constraints.

Future Improvements

Implementing constraint propagation for better performance.

Adding a graphical user interface (GUI).

Extending to Sudoku puzzles of different sizes.

Contributing

Feel free to contribute by improving efficiency, adding new features, or fixing bugs.

License

This project is open-source and free to use under the MIT License.
