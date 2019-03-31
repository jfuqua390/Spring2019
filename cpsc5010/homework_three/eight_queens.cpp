#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#define N 8
using namespace std;

/*
The classic Eight Queens puzzle is to place eight queens on a chessboard such that no two queens
can attack each other (i.e., no two queens are on the same row, same column, or same diagonal).
There are many possible solutions. Write a program that displays one such solution.
A sample output is shown below:

|Q| | | | | | | |
| | | | |Q| | | |
| | | | | | | |Q|
| | | | | |Q| | |
| | |Q| | | | | |
| | | | | | |Q| |
| |Q| | | | | | |
| | | |Q| | | | |
*/

// Print the board given
void printSolution(int board[N][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(board[i][j] == 1) {
        cout << "|Q";
      } else {
        cout << "| ";
      }
    }
    cout << "|" << endl;
  }
}

// Check to see if the spot on the board can take a queen
bool isItSafe(int board[N][N], int row, int col) {
  int i, j;
  for(i = 0; i < col; i++) {
    if(board[row][i]) {
      return false;
    }
  }

  for(i = row, j=col; i >= 0 && j >= 0; i--, j--) {
    if(board[i][j]) {
      return false;
    }
  }

  for(i = row, j = col; j >= 0 && i < N; i++, j--) {
    if(board[i][j]) {
      return false;
    }
  }

  return true;
}

//Actually run through the board and see where to place queens (1s are queens clearly)
bool solve(int board[N][N], int col) {
  if(col >= N) {
    return true;
  }
  for(int i = 0; i < N; i++) {
    if(isItSafe(board, i, col)) {
      board[i][col] = 1;
      if(solve(board, col + 1) == true) {
        return true;
      }
      board[i][col] = 0;
    }
  }

  return false;
}

int main() {
  int actualBoard[N][N] = {0};
  if(solve(actualBoard, 0) == false) {
    cout << "No solution" << endl;
    return 0;
  }
  printSolution(actualBoard);
}
