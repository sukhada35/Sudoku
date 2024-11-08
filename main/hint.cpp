#include<iostream>
#include<vector>
using namespace std;
void giveHint(vector<vector<int>>& board, vector<pair<int, int>>& emptyCells, vector<vector<int>>& correctBoard) 
{
    if (emptyCells.empty()) 
    {
        cout << "No more empty cells left to reveal!\n";
        return;
    }

    // Randomly select one empty cell
    int randomIndex = rand() % emptyCells.size(); 
    int row = emptyCells[randomIndex].first; 
    int col = emptyCells[randomIndex].second;

    // Reveal this empty cell by setting it to its correct value
    // Assuming correctBoard contains the solved board
    board[row][col] = correctBoard[row][col]; // Revealing the number in the puzzle

    // Remove this cell from the list of empty cells
    emptyCells.erase(emptyCells.begin() + randomIndex);
}