#ifndef __getMoves
#define __getMoves

#include <cstdlib>

using namespace std;

void getMoves(int newGameState[3][1][3], int currentState[]){                           //just modifies 3D array of moves, doesnt return anything
   
  if (currentState[0] >= currentState[1]){
    newGameState[0][0][0] = currentState[0] - currentState[1];                          //first move is 1st pile minus 2nd pile
    newGameState[0][0][1] = currentState[1];                                            //sorting is done in main function when called
    newGameState[0][0][2] = currentState[2];
  }
  
  if ((currentState[1] >= currentState[2]) && currentState[2] != 0){                    //not valid move if 3rd pile is 0
    newGameState[1][0][0] = currentState[0];
    newGameState[1][0][1] = currentState[1] - currentState[2];
    newGameState[1][0][2] = currentState[2];
  }
  
  if ((currentState[0] >= currentState[2]) && (currentState[2] != 0)){                  //not valid if 3rd pile is 0
    newGameState[2][0][0] = currentState[0] - currentState[2];
    newGameState[2][0][1] = currentState[1];
    newGameState[2][0][2] = currentState[2];
  }
  
  
}

#endif