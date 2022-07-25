#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  CardList Alice, Bob;
  char suit, value;

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    Alice.append(new Card(suit, value));
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    Bob.append(new Card(suit, value));
  }
  cardFile2.close();

  // Start the game
  bool match = 0;
  bool turn = 1;

  while(turn) { 
    for (Card* i = Alice.head; i != NULL; i = i->next) { // Alice's turn
      if(Bob.search(i)) {
        cout << "Alice picked matching card " << *i << endl;
        Bob.remove(Bob.search(i));
        Alice.remove(Alice.search(i));
        match = 1;
        break;
      }
    }
    if (match == 0) {
      turn = 0;
    }
    if (match == 1) {
      match = 0;
      for (Card* j = Bob.head; j != NULL; j = j->next) { // Bob's turn
        if(Alice.search(j)) {
          cout << "Bob picked matching card " << *j << endl;
          Alice.remove(Alice.search(j));
          Bob.remove(Bob.search(j));
          match = 1;
          break;
        }
      } 
      if (match == 0) {
        turn = 0;
      }
    }
  }
  cout << endl;
  cout << "Alice's cards: " << endl;
  for (Card *n = Alice.head; n != NULL; n = n->next) {
    cout << *n << endl;
  }
  cout << endl;
  cout << "Bob's cards: " << endl;
  for (Card *m = Bob.head; m != NULL; m = m->next) {
    cout << *m << endl;
  }  
  return 0;
}

