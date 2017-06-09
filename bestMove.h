#ifndef __bestMove
#define __bestMove

#include <cstdlib>
#include "getMoves.h"
#include "isWinner.h"

using namespace std;

void bestMove (int newGameState[3][1][3], int currentState[], int bestMove[]){
  
  getMoves(newGameState, currentState);                                                             //pointer pointing to 3D array of possible moves

  int move[3] = {};
  
  for (int j = 0; j < 3; j++){                                                                      //iterate through 1st move's row making game state
    move[j] = newGameState[0][0][j];
  }
  if (isWinner(newGameState, move, 1) == true){                                                     //if move results in a winning game make that move
    for (int n = 0; n < 3; n++){
      bestMove[n] = move[n];
    }
  }
  else {                                                                                            //if not try the next move
    for(int i = 0; i < 3; i++){                                                                     //iterate through row in 3D array making game state
      move[i] = newGameState[1][0][i];
    }
    if (isWinner(newGameState, move, 1) == true){                                                              
      for (int m = 0; m < 3; m++){
        bestMove[m] = move[m];
      }
    }
    else{                                                                                       //getting to this point means move 3 is best move
      for (int k = 0; k < 3; k++){
        bestMove[k] = newGameState[2][0][k];
      }
    }
  }
}
  
#endif