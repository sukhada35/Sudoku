#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// Function to check if placing num in board[row][col] is valid
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) return false;
    }

    // Check the column
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) return false;
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Backtracking function to solve Sudoku
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // Find an empty cell
            if (board[row][col] == 0) {
                // Try digits 1-9
                for (int num = 1; num <= 9; num++) {
                    // Check if it’s safe to place num
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num; // Place the number

                        // Recur to try to fill in the rest
                        if (solveSudoku(board)) {
                            return true; // If solved, return true
                        }

                        // If placing num didn’t lead to a solution, backtrack
                        board[row][col] = 0; // Reset the cell
                    }
                }
                return false; // No valid number found, backtrack
            }
        }
    }
    return true; // Puzzle solved
}

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example Sudoku board (0 represents empty cells)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}