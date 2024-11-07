const int SIZE = 9;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
// Include your additional headers for Sudoku functionality
#include "emptyspaces.cpp"
#include "solver.cpp"
#include "checker.cpp"
#include "creator.cpp"

using namespace std;


char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Function to give hints to the user by revealing an empty cell
void giveHint(vector<vector<int>>& board, vector<pair<int, int>>& emptyCells, vector<vector<int>>& correctBoard) {
    if (emptyCells.empty()) {
        cout << "No more empty cells left to reveal!\n";
        return;
    }
    cout << "Hint: Revealing an empty cell...\n";
    // Randomly select one empty cell
    int randomIndex = rand() % emptyCells.size();
    int row = emptyCells[randomIndex].first;
    int col = emptyCells[randomIndex].second;

    // Reveal this empty cell by setting it to its correct value
    // board[row][col] = correctBoard[row][col];  // Revealing the number in the puzzle

    cout << "Revealed cell at row " << row + 1 << ", column " << col + 1 << " with value " << correctBoard[row][col] << endl;
    // Remove this cell from the list of empty cells
    emptyCells.erase(emptyCells.begin() + randomIndex);
}

// Function to input the user's board solution
void inputUserBoard(vector<vector<int>>& userBoard) {
    cout << "Enter your Sudoku solution (9x9 grid, row by row, with values 1-9 or 0 for empty cells):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter row " << i + 1 << " (space-separated values): ";
        for (int j = 0; j < SIZE; j++) {
            cin >> userBoard[i][j];
        }
    }
}

vector<pair<int, int>> findEmptySpaces(const vector<vector<int>>& board) {
    vector<pair<int, int>> emptyCells;  // Vector to store coordinates of empty cells

    // Loop through the board to find empty cells (cells with value 0)
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {  // If the cell is empty
                emptyCells.push_back(make_pair(row, col));  // Add its coordinates to the list
            }
        }
    }

    return emptyCells;  // Return the list of empty cells
}

// Main function to drive the game
int main() {
    srand(time(0));  // Seed for random number generation

    while (true) {
        vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // Initialize board
        vector<vector<int>> correctBoard(SIZE, vector<int>(SIZE, 0)); // Initialize correct board
        vector<vector<int>> userBoard(SIZE, vector<int>(SIZE, 0)); // Initialize userBoard
        int hintCounter = 3; // The user starts with 3 hints

        // Call findEmptySpaces to get a list of empty cells
        vector<pair<int, int>> emptyCells = findEmptySpaces(board);
        char hintChoice;    

        // Print the coordinates of empty cells
        cout << "Empty cells coordinates:\n";
        for (auto& cell : emptyCells) {
            cout << "(" << cell.first + 1 << ", " << cell.second + 1 << ")\n";  // +1 to show 1-based index
        }

        int seed = rand() % SIZE + 1;
        board[0][0] = seed;

        char choice;
        int emptyCellsCount = 0;

        // Creator Code ================================================================================================
        if (fillSudoku(board, 0, 1)) {
            cout << "Board exists!" << endl;
        } else {
            cout << "No solution exists" << endl;
            continue; // Restart the loop if no solution is found
        }
        
        correctBoard = board; // Save the solved board

        // Choose difficulty ===========================================================================================
        cout << "Enter the difficulty:\nE for Easy\nM for Medium\nH for Hard\n";
        cin >> choice;
        choice = toUpper(choice);
        switch (choice) {
            case 'E':
                emptyCellsCount = 25;
                break;
            case 'M':
                emptyCellsCount = 35;
                break;
            case 'H':
                emptyCellsCount = 50;
                break;
            default:
                cout << "Invalid Input, Try again\n";
                continue;  // Go back to the difficulty selection
        }

        // Create empty spaces ========================================================================================
        createEmptySpaces(board, emptyCellsCount);
        emptyCells = findEmptySpaces(board); // Get the list of empty cells

        cout << "\nSudoku Puzzle for the User to Solve:\n";
        printBoard(board);  // Display the initial puzzle

        // Game Loop for User Input ====================================================================================
        while (true) {
            // Ask if the user wants a hint
            if (hintCounter > 0) {
                cout << "You have " << hintCounter << " hint(s) remaining.\n";
                cout << "Do you want a hint? (y/n): ";
                cin >> hintChoice;
                // Provide a hint if the user chooses 'y' or 'Y'
                if (hintChoice == 'y' || hintChoice == 'Y') {
                    giveHint(board, emptyCells, correctBoard);  // Provide a hint by revealing an empty cell
                    hintCounter--;  // Decrement the hint counter
                }
                // else
                //     break;
            }

            else if (hintChoice == 'n' || hintChoice == 'N') {
                break;  // Exit the hint loop if the user chooses not to get a hint
            }
        }

        // After the game, ask for user input to compare the solution
        cout << "Enter your Sudoku solution (9x9 grid):\n";
        inputUserBoard(userBoard);  // Get the user's solution for comparison

        cout << "Expected solution:\n";
        printBoard(correctBoard);  // Print the correct solution
        
        if (compareBoards(userBoard, correctBoard)) {
            cout << "Correct\n";
        } else {
            cout << "Wrong\n";
        }

        // Exit the program
        cout << "Ending execution...\n";
        break;  // Exit the main loop
    }

    return 0;
}
