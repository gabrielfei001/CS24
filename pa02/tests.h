// tests.h
// Anika Arora, Gabriel Fei
// 5/29/20

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
using namespace std;

void runTests();
void test_constructor();
void test_destructor();
void test_printPreOrder();
void test_n_visited();
void test_countNodes();
void test_highestRating();

void startTest(string test) {
    cout << "Start: " << test << endl;
}

void endTest(string test) {
    cout << "End: " << test << endl;
}
#endif