// Size of the Sudoku board is constant throughout the program
const int SIZE = 9;  
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "emptyspaces.cpp"
#include "solver.cpp"
#include "checker.cpp"
#include "creator.cpp"

int main()
{
    //1. Creator: random correct board: 3 difficulties, calls emptyspaces to add empty spaces, gives output
    //2. Checker: User input, code will create output for it and check if it is correct
    //3. EXIT
    //there will be a timer in the background 
    //user can choose one of the two choices and the code will run the respective function
    //if the user chooses EXIT, the code will terminate
    //====================================================================================================MENU
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
    srand(time(0));

    // Set a random number (between 1 and 9) as the seed in the top-left cell
    int seed = rand() % SIZE + 1;
    board[0][0] = seed;

    int option;
    cout << "Choose an option:\n1. Creator\n2. Checker\n3. EXIT\n";
    cin >> option;
    
    switch (option)
    {
    case 1:
        //Creator Code: this code generates the sudoku board without empty spaces

        if (fillSudoku(board, 0, 1)) {  // Start filling from the second cell
            printBoard(board);
        } else {
            cout << "No solution exists" << endl;
        }

        //this part of the code will generate the empty spaces in the board
        //Number of cells to empty for the user to solve
        int emptyCells;  
        char choice;
        cout << "Enter the difficulty:\nE for Easy\nM for Medium\nH for Hard\n";
        cin >> choice;
        userChoice:
        switch(choice){
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
            goto userChoice;
        }
        // Create empty spaces in the correct Sudoku board
        createEmptySpaces(board, emptyCells);
        // Display the board with empty spaces to the user
        cout << "\nSudoku Puzzle for the User to Solve:\n";
        printBoard(board);
        break;
    case 2:
        //Checker
        break;
    case 3:
        //EXIT
        break;
    default:
        break;
    }
    //====================================================================================================EMPTY SPACES

 
    return 0;
    //====================================================================================================SOLVER
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
    //====================================================================================================SUDOKU CHECKER
    int userBoard[9][9];    // To store user input board
    // int correctBoard[9][9]; // To store the correct solved board
    // Input the user board
    cout << "Enter the User Sudoku Board (9x9):\n";
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cin >> userBoard[i][j];
        }
    }

    // Input the correct board
    cout << "Enter the Correct Sudoku Board (9x9):\n";
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cin >> correctBoard[i][j];
        }
    }

    // Compare the two boards
    if (compareBoards(userBoard, correctBoard)) 
    {
        cout << "Correct\n"; // If the boards match
    } 
    else 
    {
        cout << "Wrong\n";   // If the boards don't match
    }

    return 0;
}
