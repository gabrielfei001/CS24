//cards.h
//Authors: Gabriel Fei
//All class declarations go here
#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
using namespace std;

class Card {
    public: 
        // Constructor, class functions of Card
        Card(char a, char b);
        friend std::ostream& operator<<(std::ostream& os, const Card& c); // overload the << operator to print CardList elements
        bool operator==(const Card& c); // compare cards in CardList
        Card* next; // pointer to next Card 
        char suit;
        char value;
};

class CardList {
    public: 
        // Constructor, Destructor, class functions of CardList
        CardList(); 
        ~CardList();
        int search(Card *c); // search for Card in CardList
        void remove(int x); // remove Card from CardList
        void append(Card *c); // add Card to end of CardList
        void clear(); // delete all the cards
        void assertEquals(Card *c, Card *d);
        // Pointers to first, last, current and previous card
        Card *head;
        Card *tail;
    private:
        void clearhelper(Card *c); // recursive helper for clear
};


#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
