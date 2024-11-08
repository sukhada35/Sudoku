#include <iostream>
#include <vector>
// #include <cstdlib>
// #include <ctime>

using namespace std;

// Function to check if placing a number `num` at position (row, col) is safe
bool isSafe(vector<vector<int>>& board, int row, int col, int num) 
{
    for (int x = 0; x < SIZE; x++) 
    {
        if (board[row][x] == num || board[x][col] == num) return false; // Check row and column
    }

// Check the 3x3 subgrid that contains the position (row, col)
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool fillSudoku(vector<vector<int>>& board, int row, int col) 
{
    if (row == SIZE - 1 && col == SIZE) return true; // If we have reached the end of the board
    if (col == SIZE) { row++; col = 0; } // Move to the next row if we have reached the end of the column

    if (board[row][col] != 0) return fillSudoku(board, row, col + 1); // Skip the filled cells

    for (int num = 1; num <= SIZE; num++) 
    {
        if (isSafe(board, row, col, num)) 
        {
            board[row][col] = num;
            if (fillSudoku(board, row, col + 1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

// void printBoard(const vector<vector<int>>& board) {
//     for (int r = 0; r < SIZE; r++) {
//         for (int d = 0; d < SIZE; d++) {
//             cout << board[r][d] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
//     srand(time(0));

//     // Set a random number (between 1 and 9) as the seed in the top-left cell
//     int seed = rand() % SIZE + 1;
//     board[0][0] = seed;

//     if (fillSudoku(board, 0, 1)) {  // Start filling from the second cell
//         printBoard(board);
//     } else {
//         cout << "No solution exists" << endl;
//     }

//     return 0;
// }
