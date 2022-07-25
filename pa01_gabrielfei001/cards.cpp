//cards.cpp
//Authors: Gabriel Fei
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(char a, char b) {
    suit = a;
    value = b; 
    next = 0;
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << c.suit << " " << c.value;
    return os;
}

bool Card::operator==(const Card& c) {
    if((suit == c.suit) && (value == c.value)) {
        return true;
    }
    else {
        return false;
    }
}

CardList::CardList() {
    head = 0;
    tail = 0;
}

void CardList::clearhelper(Card *c) {
    if(!c) {
        return;
    }
    clearhelper(c->next);
    delete c;
}

CardList::~CardList() {
    clearhelper(head);
    head = tail = 0;
}

void CardList::append(Card* c) {
    if ((head == 0) && (tail == 0)) { 
        head = c;
	    tail = c;
    }
    else { 
        tail->next = c;
        tail = c;
    }
}

int CardList::search(Card *c) {
    int count = 0;
    Card *p = head;
    while (p) {
        count ++;
        if (*p == *c) {    
            return count;
        }
        p = p->next;
    }
    return 0;
}


void CardList::remove(int c) {
    if (c == 0) {
        return;
    }
    if (c == 1) {
        if (head == tail) {
            delete head;
        }
        else {
            Card *p = head;
            head = head->next;
            delete p;
        }
        return;
    }
    else {
        int counter = 2;
        Card* q = head;
        while (q) {
            if (c == counter) {
                Card *w = q->next;
                q->next = q->next->next;
                delete w;
            }
            q = q->next;
            counter ++;
        }
    }
    return;
}