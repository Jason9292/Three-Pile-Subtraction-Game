#ifndef __isWinner
#define __isWinner

#include <cstdlib>
#include "getMoves.h"
#include "Sort.h"

using namespace std;

int gameTracker[][1][3] = {{{}},{{}},{{}}};                                                                 //3D array to hold used game states for memoization
bool isKnown[] = {};                                                                                        //index will match gameTracker, determines if seen
bool isWin[] = {};                                                                                          //index will match, determines if winner

bool isWinner(int newGameState[3][1][3], int currentState[], int turn){                                     //turn parameter desides who goes first
  
  Sort(currentState);                                                                                       //needs to be sorted for compare
  
  int a = sizeof((gameTracker))/sizeof((gameTracker[0]));                                                   //to get number of moves
  for (int i = 0; i < a; i++){
    if ((gameTracker[a][1][0] == currentState[0]) && (gameTracker[a][1][1] == currentState[1]) && (gameTracker[a][1][2] == currentState[2])){
      if ((isKnown[a]) == true && (turn %2 == 0)){                                                          //turn goes to even AFTER AI turn
        if (isWin[a] == true){                                                                              //use memoized storage to save recursive calls
          return true;
          break;
        }
        else{
          return false;
          break;
        }
      }
      else if((isKnown[a]) == true && (turn %2 != 0)){                                                      
        if (isWin[a] == true){
          return false;
          break;
        }
        else{
          return true;
          break;
        }
      }
    }
  }
  
  gameTracker[a][1][0] = currentState[0];                                                                  //if it hasn't already been seen
  gameTracker[a][1][1] = currentState[1];                                                                  //add it to the data structure
  gameTracker[a][1][2] = currentState[2];
  
  turn = turn + 1;                                                                                       //increment turn variable
  
  getMoves(newGameState, currentState);                                                                    //update array of next moves
  
  if ((currentState[1] == 0) && (turn %2 == 0)){                                                           //if 2 piles are 0 and AI made last move
    isKnown[a] = true;                                                                                     //update memoize functions
    isWin[a] = true;
    return true;                                                                                           //return true
  }
  else if ((currentState[1] == 0) && (turn %2 != 0)){                                                      //if game ends after user's last move
    isKnown[a] = true;                                                                                     //update memoize functions
    isWin[a] = false;
    return false;                                                                                          //return false
  }
  else{                                                                                                    //if game doesn't end and another move is to be mad
    int firstMove[3] = {};
    int secondMove[3] = {};                                                                                //store resulting game states for each move
    int thirdMove[3] = {};
  
    for (int j = 0; j < 3; j++){
      firstMove[j] = newGameState[0][0][j];                                                               //populate resulting game states
    }
    for (int k = 0; k < 3; k++){
      secondMove[k] = newGameState[1][0][k]; 
    }
    for (int m = 0; m < 3; m++){
      thirdMove[m] = newGameState[2][0][m]; 
    }
    
    if ((isWinner(newGameState, firstMove, turn) == true) || (isWinner(newGameState, secondMove, turn) == true) || (isWinner(newGameState, thirdMove, turn) == true)){
      isKnown[a] = true;                                                                                  //if a move results in a winning game
      isWin[a] = true;                                                                                    //return true and update memoize functions
      return true;
    }
  } 
  
  isKnown[a] = true;                                                                                      //if nothing update and return false
  isWin[a] = false;
  return false;
  
}
        

#endif







