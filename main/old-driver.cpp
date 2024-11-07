// const int SIZE = 9;
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// // Include your additional headers for Sudoku functionality
// #include "emptyspaces.cpp"
// #include "solver.cpp"
// #include "checker.cpp"
// #include "creator.cpp"
// #include "hint.cpp"

// using namespace std;

// char toUpper(char c) {
//     if (c >= 'a' && c <= 'z') {
//         return c - 'a' + 'A';
//     }
//     return c;
// }

// int main() 
// {
//     // srand(time(0));

//     while (true) {
//         vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // Initialize board
//         vector<vector<int>> correctBoard(SIZE, vector<int>(SIZE, 0)); // Initialize board
//         vector<vector<int>> userBoard(SIZE, vector<int>(SIZE, 0)); // Initialize userBoard
//         int hintCounter = 3; // The user starts with 3 hints

//         int seed = rand() % SIZE + 1;
//         board[0][0] = seed;

//         int emptyCells = 0; // Initialize emptyCells
//         char choice;

//         // Creator Code ================================================================================================
//         if (fillSudoku(board, 0, 1)) {
//             cout << "Board exists!" << endl;
//             // cout << "Solved board:" << endl;
//             // printBoard(board);
//         } else {
//             cout << "No solution exists" << endl;
//             continue; 
//         }
//         correctBoard = board; // Save the correct board
//         cout << "Enter the difficulty:\nE for Easy\nM for Medium\nH for Hard\n";
//         cin >> choice;
//         choice = toUpper(choice);
//         switch (choice) {
//             case 'E':
//                 emptyCells = 25;
//                 break;
//             case 'M':
//                 emptyCells = 35;
//                 break;
//             case 'H':
//                 emptyCells = 50;
//                 break;
//             default:
//                 cout << "Invalid Input, Try again\n";
//                 continue; // Go back to the menu
//         }

//         // Create empty spaces ========================================================================================
//         createEmptySpaces(board, emptyCells);
//         cout << "\nSudoku Puzzle for the User to Solve:\n";
//         printBoard(board);

//         //Hint thingy comes here ======================================================================================
//         // Ask if the user wants a hint
//         while (true) {
//             cout << "\nEnter the numbers for the puzzle (or enter -1 to quit):\n";
//             printBoard(board); // Print the current state of the board

//             // Prompt the user for input
//             int row, col, value;
//             cout << "Enter row (1-9), column (1-9), and value (1-9): ";
//             cin >> row >> col >> value;

//             // Check for quit condition
//             if (row == -1 || col == -1 || value == -1) {
//                 cout << "Exiting the game..." << endl;
//                 break;
//             }

//             // Validate the input and update the board
//             if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && value >= 1 && value <= SIZE) {
//                 board[row - 1][col - 1] = value; // Adjusting for 0-based indexing
//             } else {
//                 cout << "Invalid input. Try again.\n";
//                 continue;
//             }

//             // Ask if the user wants a hint
//             if (hintCounter > 0) {
//                 cout << "You have " << hintCounter << " hints remaining.\n";
//                 cout << "Do you want a hint? (y/n): ";
//                 char hintChoice;
//                 cin >> hintChoice;

//                 if (hintChoice == 'y' || hintChoice == 'Y') {
//                     giveHint(board, emptyCells);  // Provide a hint by revealing an empty cell
//                     hintCounter--;  // Decrement the hint counter
//                 }
//             }

//             // Check if the user has solved the puzzle
//             if (compareBoards(board, correctBoard)) {
//                 cout << "Congratulations, you solved the puzzle!\n";
//                 break;
//             }
//         }
//         // Checker Code ===============================================================================================
//         cout << "Enter the User Sudoku Board (9x9):\n";
//         for (int i = 0; i < SIZE; i++) {
//             for (int j = 0; j < SIZE; j++) {
//                 cin >> userBoard[i][j];
//             }
//         }
//         cout << "Expected output\n";
//         printBoard(correctBoard);
//         if (compareBoards(userBoard, correctBoard)) {
//             cout << "Correct\n";
//         } else {
//             cout << "Wrong\n";
//         }
//         break; // Exit after case 2

//         cout << "Ending execution...";
//         return 0;

//         // cerr << "Invalid Input!";
//         // break;
        
//     }
// }