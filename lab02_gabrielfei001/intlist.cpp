// intlist.cpp
// Implements class IntList
// Gabriel Fei 4/21/20

#include "intlist.h"
#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node *p1 = 0;
    Node *p2 = 0;
    if (source.first == 0) {
        first = 0;
    } else {
        first = new Node;
        first->info= source.first->info;
        p1 = first;
        p2 = source.first->next;
    }
    while (p2) {
        p1->next = new Node;
        p1 = p1->next;
        p1->info = p2->info;
        p2 = p2->next;
    }
    p1->next = 0;
}

// destructor deletes all nodes
IntList::~IntList() {
    Node *p3;
    while (first != NULL) {
        p3 = first->next;
        delete first;
        first = p3;
    }
    delete p3;
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *n = first;
    while (n) {
        sum = sum + n->info;
        n = n->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for (Node *n = first; n != 0; n = n->next) {
        if (n->info == value) {
            return true;
        }
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max;
    if (first == 0) {
        return 0;
    } else {
        Node *n = first;
        max = n->info;
        while (n) {
            if (n->info > max) {
                max = n->info;
            }
            n = n->next;
        }
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double avg = 0.0;
    double sum = 0.0;
    int count = 0;
    Node *n = first;
    if (first == 0) {
        return 0;
    } else {
        while (n) {
            sum = sum + n->info;
            count++;
            n = n->next;
        }
        avg = sum / count;
    }
    return avg;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if (first == 0) {
        first = new Node;
        first->info = value;
        first->next = 0;
    } else {
        Node *temp = first;
        first = new Node;
        first->info = value;
        first->next = temp;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source) {
    first = 0;
    Node *p = source.first;
    while (p){
        append(p->info);
        p = p->next;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
