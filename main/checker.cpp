#include <iostream>
#include <vector>
using namespace std;

// Function to compare two Sudoku boards
bool compareBoards(const vector<vector<int>>& userBoard, const vector<vector<int>>& correctBoard) 
{
    for (int i = 0; i < 9; i++)     // Traverse through each cell of the 9x9 board
    {
        for (int j = 0; j < 9; j++) 
        {
            if (userBoard[i][j] != correctBoard[i][j])      // If any cell doesn't match, return false
            {
                return false;
            }
        }
    }
    return true; // Return true if all cells match
}

// int main() 
// {
//     int userBoard[9][9];    // To store user input board
//     int correctBoard[9][9]; // To store the correct solved board

//     // Input the user board
//     cout << "Enter the User Sudoku Board (9x9):\n";
//     for (int i = 0; i < 9; i++) 
//     {
//         for (int j = 0; j < 9; j++) 
//         {
//             cin >> userBoard[i][j];
//         }
//     }

//     // Input the correct board
//     cout << "Enter the Correct Sudoku Board (9x9):\n";
//     for (int i = 0; i < 9; i++) 
//     {
//         for (int j = 0; j < 9; j++) 
//         {
//             cin >> correctBoard[i][j];
//         }
//     }

//     // Compare the two boards
//     if (compareBoards(userBoard, correctBoard)) 
//     {
//         cout << "Correct\n"; // If the boards match
//     } 
//     else 
//     {
//         cout << "Wrong\n";   // If the boards don't match
//     }

//     return 0;
// }
