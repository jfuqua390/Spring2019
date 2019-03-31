#include <iostream>
using namespace std;
/*
In a game of tic-tac-toe, two players take turns marking an available cell in a 3 * 3 grid with
their respective tokens (either X or O).
When one player has placed three tokens in a horizontal, vertical, or diagonal row on the grid,
the game is over and that player has won. A draw (no winner) occurs when all the cells on the grid
have been filled with tokens and neither player has achieved a win. Create a program for playing tic-tac-toe.

The program prompts two players to enter an X token and O token alternately.
Whenever a token is entered, the program redisplays the board on the console
and determines the status of the game (win, draw, or continue).
*/

char matrix[3][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
char player = 'x';

void board() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(j < 2) {
        cout << matrix[i][j] << " | ";
      } else {
        cout << matrix[i][j];
      }
    }
    if(i < 2) {
      cout << endl << "----------" << endl;
    }
  }
  cout << endl;
}

void input() {
  int move;
  cout << "Press the number you want to play on: ";
  cin >> move;

  cout << "Chose: " << move << endl;
  if(move == 1) {
    matrix[0][0] = player;
  } else if(move == 2) {
    matrix[0][1] = player;
  } else if(move == 3) {
    matrix[0][2] = player;
  } else if(move == 4) {
    matrix[1][0] = player;
  } else if(move == 5) {
    matrix[1][1] = player;
  } else if(move == 6) {
    matrix[1][2] = player;
  } else if(move == 7) {
    matrix[2][0] = player;
  } else if(move == 8) {
    matrix[2][1] = player;
  } else if(move == 9) {
    matrix[2][2] = player;
  } else {
    cout << "Invalid input" << endl;
  }
}

void change_player() {
  if(player == 'x') {
    player = 'o';
  } else {
    player = 'x';
  }
}

int checkwin() {
  if(matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]) {
    return 1;
  } else if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2]) {
    return 1;
  } else if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2]) {
    return 1;
  } else if(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]) {
    return 1;
  } else if(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1]) {
    return 1;
  } else if(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]) {
    return 1;
  } else if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
    return 1;
  } else if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
    return 1;
  } else if(matrix[0][0] != '1' && matrix[0][1] != '2' && matrix[0][2] != '3' &&
            matrix[1][0] != '4' && matrix[1][1] != '5' && matrix[1][2] != '6' &&
            matrix[2][0] != '7' && matrix[2][1] != '8' && matrix[2][2] != '9'){
    return 2;
  } else {
    return 0;
  }
}

int main() {
  board();
  while(checkwin() < 1) {
    input();
    board();
    change_player();
  }
  if(checkwin() == 2) {
    cout << "Game ends in a draw!" << endl;
  } else {
    change_player();
    cout << endl << "Player "<< player << " won!" << endl;
  }
}
