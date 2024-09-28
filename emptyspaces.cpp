#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 9;  // Size of the Sudoku board

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == 0) 
            {
                cout << ". ";  // Empty cells represented by '.'
            } 
            else 
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Function to randomly create empty spaces in the board
void createEmptySpaces(int board[SIZE][SIZE], int emptyCells) 
{
    srand(time(0));  // Seed for random number generation

    int count = 0;
    while (count < emptyCells) 
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        // Only create an empty space if the cell is not already empty
        if (board[row][col] != 0) 
        {
            board[row][col] = 0;
            count++;
        }
    }
}

int main() 
{
    // A pre-solved correct Sudoku board
    int correctBoard[SIZE][SIZE] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    int emptyCells;  // Number of cells to empty for the user to solve
    cout << "Enter the number of empty cells to create for the user: ";
    cin >> emptyCells;

    // Create empty spaces in the correct Sudoku board
    createEmptySpaces(correctBoard, emptyCells);

    // Display the board with empty spaces to the user
    cout << "\nSudoku Puzzle for the User to Solve:\n";
    printBoard(correctBoard);

    return 0;
}