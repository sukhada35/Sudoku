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

int main() 
{
    // srand(time(0));

    while (true) {
        vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // Initialize board
        vector<vector<int>> correctBoard(SIZE, vector<int>(SIZE, 0)); // Initialize board
        vector<vector<int>> userBoard(SIZE, vector<int>(SIZE, 0)); // Initialize userBoard

        int seed = rand() % SIZE + 1;
        board[0][0] = seed;

        int option = 0;
        cout << "Choose an option:\n1. Creator\n2. Checker\n3. EXIT\n";
        cin >> option;

        int emptyCells = 0; // Initialize emptyCells
        char choice;

        switch (option) {
        case 1:
            // Creator Code
            if (fillSudoku(board, 0, 1)) {
                cout << "Solved board:" << endl;
                printBoard(board);
            } else {
                cout << "No solution exists" << endl;
                continue; // Go back to the menu
            }
            correctBoard = board; // Save the correct board
            cout << "Enter the difficulty:\nE for Easy\nM for Medium\nH for Hard\n";
            cin >> choice;
            choice = toUpper(choice);
            switch (choice) {
                case 'E':
                    emptyCells = 25;
                    break;
                case 'M':
                    emptyCells = 35;
                    break;
                case 'H':
                    emptyCells = 50;
                    break;
                default:
                    cout << "Invalid Input, Try again\n";
                    continue; // Go back to the menu
            }

            // Create empty spaces
            createEmptySpaces(board, emptyCells);
            cout << "\nSudoku Puzzle for the User to Solve:\n";
            printBoard(board);
            // Fall-through to case 2 (no break here)

        case 2:
            // Checker Code
            cout << "Enter the User Sudoku Board (9x9):\n";
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    cin >> userBoard[i][j];
                }
            }
            cout << "Expected output\n";
            printBoard(correctBoard);
            if (compareBoards(userBoard, correctBoard)) {
                cout << "Correct\n";
            } else {
                cout << "Wrong\n";
            }
            break; // Exit after case 2

        case 3:
            cout << "Ending execution...";
            return 0;

        default:
            cerr << "Invalid Input!";
            break;
        }
    }
}
