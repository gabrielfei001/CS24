// usestack.cpp - for CS 24 lab practice using stacks
// Gabriel Fei, May 21, 2020

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    // Evaluating "8 7 5 - + 6 *"

    // Start with empty stack
    Stack s;

    // First 3 tokens are all numbers to push "8 7 5":
    s.push(8);
    s.push(7);
    s.push(5);

    // fourth token is calculation to do "-":
    int s1 = s.top();
    s.pop();
    int s2 = s.top();
    s.pop();
    s.push(s2 - s1);

    // fifth token is another calculation to do "+":
    s1 = s.top();
    s.pop();
    s2 = s.top();
    s.pop();
    s.push(s2 + s1);
    
    // sixth token is a number to push "6":
    s.push(6);

    // last token is another calcuoation to do "*":
    s1 = s.top();
    s.pop();
    s2 = s.top();
    s.pop();
    s.push(s2 * s1);

    cout << s.top() << endl;

    return 0;
}
