#include "emptyspaces.cpp"
#include "solver.cpp"
#include "sudokuchecker.cpp"
int main()
{
    //1. Creator: random correct board: 3 difficulties, calls emptyspaces to add empty spaces, gives output
    //2. Checker: User input, code will create output for it and check if it is correct
    //====================================================================================================EMPTY SPACES
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
    char choice;
    // cout << "Enter the number of empty cells to create for the user: ";
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
    createEmptySpaces(correctBoard, emptyCells);

    // Display the board with empty spaces to the user
    cout << "\nSudoku Puzzle for the User to Solve:\n";
    printBoard(correctBoard);

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
