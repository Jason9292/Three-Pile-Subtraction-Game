#ifndef __Sort
#define __Sort

using namespace std;

void Sort(int gameState[]){
  int temp;
  
  if (gameState[0] < gameState[1]){                           //if 2nd pile bigger than 1st swap them
    temp = gameState[1];
    gameState[1] = gameState[0];
    gameState[0] = temp;
  }

  if (gameState[0] < gameState[2]){                           //if 3rd pile bigger than 1st swap them
    temp = gameState[2];
    gameState[2] = gameState[0];
    gameState[0] = temp;
  }

  if (gameState[1] < gameState[2]){                           //now 1st pile guarunteed to be biggest, swapping last 2 if necessary
    temp = gameState[2];
    gameState[2] = gameState[1];
    gameState[1] = temp;
  }
  
}

#endif