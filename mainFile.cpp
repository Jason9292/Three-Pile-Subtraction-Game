#include <iostream>
#include <cstdlib>
#include "Sort.h"
#include "isWinner.h"
#include "bestMove.h"

using namespace std;

int main(){                                                        
  int currentState [3] = {};                                                                    //array representing current state of the game
  int userChoice [2] = {};                                                                      //array representing piles user chooses
  int bestMove1 [3] = {};                                                                       //array representing bestMove
  
  int newGameState[3][1][3] = {{{}},{{}},{{}}};                                                 //3D array to hold resulting game states from each move
  
  cout << "Please enter 3 integers seperated by whitespace: "; 
  for (int i = 0; i < 3; i++){
    cin >> currentState[i];                                                                     //store the user's numbers in the current state array
  }
  
  Sort(currentState);                                                                           //will sort the array
  
  int k;
  int turn = 1;                                                                                 //variable to help determine who goes first
  
  if (isWinner(newGameState, currentState, 1) == true){                                         //if it is a winning game, AI goes first
    cout << "I'll go first" << endl;
    while (currentState[1] != 0){                                                               //while the game still has at least 2 piles
      if (turn % 2 != 0){                                                                       //if turn variable is odd, AI goes
        bestMove(newGameState, currentState, bestMove1);                                        //best move has now been made
        for (k = 0; k < 3; k++){
          currentState[k] = bestMove1[k];                                                       //matching current state to best move
        }
        Sort(currentState);                                                                     //sorting the newly affected array
        cout << "New game state is: ";
        cout << currentState[0] << ", " << currentState[1] << ", " << currentState[2] << endl;  //outputting the array
        turn = turn + 1;                                                                                 //incrementing the turn variable
      }
      else {                                                                                    //if turn is even, user goes
        cout << "Please enter 2 integers (1, 2, or 3) seperated by a space." << endl;
        cout << "1st number is pile removing from, 2nd pile is # of stones to remove: ";
        for (int j = 0; j < 2; j++){
          cin >> userChoice[j];                                                                 //store the user's choice for their move
        }
        if (userChoice[0] == 1){                                                                //calculate new game state, depending on their choice
          if (userChoice[1] == 2){
            currentState[0] = currentState[0] - currentState[1];
          }
          else{
            currentState[0] = currentState[0] - currentState[2];
          }
        }
        else{
          currentState[1] = currentState[1] - currentState[2];
        }
        Sort(currentState);
        cout << "New game state is: ";
        cout << currentState[0] << ", " << currentState[1] << ", " << currentState[2] << endl;
        turn = turn + 1;
      }
    }
  }
  
  else{
    cout << "You go first" << endl;
    turn = turn + 1;                                                                                          //increment so user goes first
    while (currentState[1] != 0){
      if (turn %2 == 0){                                  
        cout << "Please enter 2 integers (1, 2, or 3) seperated by a space." << endl;
        cout << "1st number is pile removing from, 2nd pile is # of stones to remove: ";
        for (int j = 0; j < 2; j++){
          cin >> userChoice[j];                                                                     //store the user's choice for their move
        }
        if (userChoice[0] == 1){                                                                    //calculate new game state
          if (userChoice[1] == 2){
            currentState[0] = currentState[0] - currentState[1];
          }
          else{
            currentState[0] = currentState[0] - currentState[2];
          }
        }
        else{
          currentState[1] = currentState[1] - currentState[2];
        }
        Sort(currentState);
        cout << "New game state is: ";
        cout << currentState[0] << ", " << currentState[1] << ", " << currentState[2] << endl;
        turn = turn + 1;
      }
      else{
        bestMove(newGameState, currentState, bestMove1);                                             //best move has now been made
        for (k = 0; k < 3; k++){
          currentState[k] = bestMove1[k];                                                            //matching current state to best move
        }
        Sort(currentState);
        cout << "New game state is: ";
        cout << currentState[0] << ", " << currentState[1] << ", " << currentState[2] << endl;
        turn = turn + 1;
      }
    }
  }
  
  if (turn %2 == 0){                                                                            //increments after each turn
    cout << "AI has won" << endl;                                                               //so AFTER AI moves it is even
  }
  else{
    cout << "Congratulations, something must be wrong with the code." << endl;
  } 
        
  return 0;
  
}