# C++ Matrix Game

## Overview
This C++ game allows players to navigate a matrix using arrow keys, input values, and receive hints. The game tracks mistakes, displays error messages, and features a timer to enhance gameplay.

## Features
1. **Arrow Key Navigation**: Move around the board using the arrow keys.
2. **Input Validation**: Only allows inputs from 1-9 (ASCII) and displays error messages for invalid entries.
3. **Mistake Counter**: Counts invalid inputs; if it reaches 3, the game terminates.
4. **Screen Refresh**: The screen clears and the matrix is re-displayed after each user input.
5. **Timer**: Keeps track of the time taken to complete the game.
6. **Hint Feature**: Press 'H' to reveal one empty cell.

## Requirements
- C++ compiler (e.g., g++)
- Standard libraries (e.g., `<iostream>`, `<vector>`, `<chrono>`)

## Compilation
To compile the game, use the following command:
```bash
g++ -o matrix_game matrix_game.cpp -lpthread
