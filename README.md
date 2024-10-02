# Sudoku Solver using Backtracking

## **Introduction**
This project solves an incomplete 9x9 Sudoku puzzle using the backtracking algorithm. The goal is to fill the board such that every row, column, and 3x3 sub-grid contains the digits 1 to 9 exactly once.

## **Problem Statement**
Given a 9x9 Sudoku grid, the task is to complete the puzzle while adhering to the following rules:

1. **Each row** must contain the digits 1 to 9, without repetition.
2. **Each column** must contain the digits 1 to 9, without repetition.
3. **Each 3x3 sub-grid** must contain the digits 1 to 9, without repetition.

*Note*: The character `'.'` represents an empty cell that needs to be filled.

## **Approach**

### **Intuition**
The problem can be tackled using **backtracking**, a method of trying all possible solutions for each empty cell. The algorithm recursively fills the grid by trying every valid number in each empty cell. If at any point the board becomes invalid, it backtracks to the previous state and tries a different number.

### **Recursive Solution**
1. **Recursion and Board Traversal**:  
   The algorithm traverses the Sudoku grid cell by cell. When an empty cell is encountered, it attempts to place digits (1-9) in that cell.

2. **Validity Check**:  
   For each number placed, the algorithm checks if the board remains valid based on the Sudoku rules. If the number violates any rules, it is discarded, and another number is tried. This validation ensures that the solution adheres to the row, column, and sub-grid constraints.

3. **Backtracking**:  
   If no valid number can be placed in a particular cell, the algorithm backtracks to the previous cell and tries a different number. This process continues until the board is completely filled or all possibilities are exhausted.

### **Board Validation**
To ensure the board remains valid after placing a number, the algorithm checks three conditions for every cell:

1. **Row Validation**: The number should not already exist in the current row.
2. **Column Validation**: The number should not already exist in the current column.
3. **Sub-grid Validation**: The number should not already exist in the corresponding 3x3 sub-grid.

These checks are performed for each cell to maintain the integrity of the Sudoku puzzle.

### **Early Termination**
If a valid solution is found at any point, the algorithm terminates early and returns the completed board.


## **How It Works**
The algorithm works by:

1. **Identifying empty cells** in the grid.
2. **Trying all possible numbers** (1-9) for each empty cell.
3. **Checking the validity** of each number based on Sudoku rules.
4. **Using backtracking** to explore all possible solutions.
5. **Terminating** when a valid solution is found or all possibilities are exhausted.

## **Conclusion**
This backtracking-based Sudoku solver efficiently fills incomplete puzzles while ensuring the final board adheres to Sudoku rules. By trying all possible configurations and backtracking when necessary, the algorithm guarantees that the solution found is valid.

## **Future Improvements**
- Optimize the algorithm further by pre-filling numbers that are deterministically correct based on current board constraints.
- Implement a graphical interface for easier interaction with the Sudoku solver.

## **Credits**
This project was developed by:

- **Sukhada Gulhane** - [GitHub](https://github.com/sukhada35), Email: svvgulhane@gmail.com
- **Ashmit Jain** - [GitHub](https://github.com/ashmit27j), Email: ashmit27j@gmail.com

Feel free to reach out to us if you have any questions or suggestions!


