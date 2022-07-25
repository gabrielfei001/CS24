// tests.cpp
// Anika Arora, Gabriel Fei
// 5/29/20

#include "tests.h"
#include "movies.h"
#include <iostream>

using namespace std;

void test_constructor() {
    startTest("Test Node Constructor");
    Node n;
    if((n.name == "") && (n.rating == 0.0)) {
        cout << "PASSED: Node Constructor Test" << endl;
    }
    else {
        cout << "FAILED: Node Constructor Test" << endl;
    }
    endTest("Test Node Constructor");
    cout << endl;
    startTest("Test BST Constructor");
    BST p;
    if(p.root == NULL) {
        cout << "PASSED: BST Constructor Test" << endl;
    }
    else {
        cout << "FAILED: BST Constructor Test" << endl;
    }
    endTest("Test BST Constructor");
}

void test_destructor() {
    startTest("Test BST Destructor");
    BST* p = new BST;
    p->insert("ace ventura: when nature calls", 6.1);
    p->insert("balto", 7.1);
    p->insert("casino",7.8);
    p->insert("cutthroat island",5.7);
    p->insert("dracula: dead and loving it",5.7);
    delete p;
    cout << "Run in valgrind to check for leaks" << endl;
    endTest("Test BST Destructor");
}

void test_printPreOrder() {
    startTest("Test printPreOrder");
    BST p;
    cout << "Test Empty Tree" << endl;
    cout << "Expected: " << endl;
    cout << "Actual: ";
    p.printPreOrder();
    cout << endl;
    p.insert("ace ventura: when nature calls", 6.1);
    cout << "Test One Key BST" << endl;
    cout << "Expected: ace ventura: when nature calls, 6.1, 0" << endl;
    cout << "Actual: ";
    p.printPreOrder();
    p.insert("balto", 7.1);
    p.insert("casino",7.8);
    p.insert("cutthroat island",5.7);
    p.insert("dracula: dead and loving it",5.7);
    cout << "Test Filled BST" << endl;
    cout << "Expected: \nace ventura: when nature calls, 6.1, 0\nbalto, 7.1, 1\ncasino, 7.8, 2\ncutthroat island, 5.7, 3\ndracula: dead and loving it, 5.7, 4" << endl;
    cout << "Actual: " << endl;
    p.printPreOrder();
    endTest("Test printPreOrder");
}

void test_n_visited() {
    startTest("Test number of Nodes Visited");
    BST p;
    cout << "Expected: 0 1 2 3 4" <<  endl;
    cout << "Actual: ";
    p.insert("ace ventura: when nature calls", 6.1);
    cout << p.n_visited("ace") << " ";
    p.insert("balto", 7.1);
    cout << p.n_visited("balto") << " ";
    p.insert("casino",7.8);
    cout << p.n_visited("casino") << " ";
    p.insert("cutthroat island",5.7);
    cout << p.n_visited("cutthroat") << " ";
    p.insert("dracula: dead and loving it",5.7);
    cout << p.n_visited("dracula") << endl;
    endTest("Test number of Nodes Visited");
}

void test_countNodes() {
    startTest("Test count the number of Nodes");
    BST p;
    cout << "Empty Tree" << endl;
    cout << "Expected: 0" << endl;
    cout << "Actual: " << p.countNodes() << endl;
    p.insert("ace ventura: when nature calls", 6.1);
    cout << "Test One Key BST" << endl;
    cout << "Expected: 1" << endl;
    cout << "Actual: " << p.countNodes() << endl;
    p.insert("balto", 7.1);
    p.insert("casino",7.8);
    p.insert("cutthroat island",5.7);
    p.insert("dracula: dead and loving it",5.7);
    cout << "Test Filled BST" << endl;
    cout << "Expected: 5" << endl;
    cout << "Actual: " << p.countNodes() << endl;
    endTest("Test count the number of Nodes");
}

void test_highestRating() {
    startTest("Test Highest Rated Movie");
    BST p;
    p.insert("ace ventura: when nature calls", 6.1);
    p.insert("balto", 7.1);
    p.insert("casino",7.8);
    p.insert("cutthroat island",5.7);
    p.insert("dracula: dead and loving it",5.7);
    cout << "Expected: 7.8" << endl;
    cout << "Actual: " << p.highestRating(p.prefixNodesBST("casino", p.root))->rating << endl;
}

void runTests() {
    test_constructor();
    cout << endl;
    test_destructor();
    cout << endl;
    test_printPreOrder();
    cout << endl;
    test_n_visited();
    cout << endl;
    test_countNodes();
    cout << endl;
    test_highestRating();
}

int main() {
    runTests();
    return 0;
}