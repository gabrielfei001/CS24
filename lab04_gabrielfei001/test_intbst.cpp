// test_intbst.cpp
// Created tests for intbst.cpp

#include "intbst.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main() {
    IntBST bst1, bst2;
    
    // insert data into bst1
    bst1.insert(9);
    bst1.insert(57);
    bst1.insert(4);
    bst1.insert(32);
    bst1.insert(45);
    bst1.insert(7);
    bst1.insert(2);
    bst1.insert(3);
    bst1.insert(1);
    assert(bst1.contains(57) == true);
    assert(bst1.sum() == 160);
    assert(bst1.count() == 9);
    assert(bst1.getPredecessor(4) == 3);
    assert(bst1.getSuccessor(32) == 45);
    assert(bst1.remove(1) == true);
    return 0;
}