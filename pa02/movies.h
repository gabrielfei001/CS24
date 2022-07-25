// movies.h
// BST header file
// Anika Arora, Gabriel Fei
// 5/29/20

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <time.h>

using namespace std;

class Node {
    public:
        string name;
        double rating; 
        Node *left, *right, *parent;
        Node(string a = "", double b = 0.0): name(a), rating(b), left(0), right(0), parent(0) {}
        ~Node();
};


class BST {
    public:
        BST(); // constructor
        ~BST(); // destructor
        void search(BST& p, int N, string a); // time it takes to search BST
        void printPreOrder() const; // print pre-order traversal
        void searchAllNodes() const; // search through all Nodes
        bool insert(string a, double b); // insert into Node of BST
        int n_visited(string a) const; // count number of Nodes visited
        int countNodes() const; // count all Nodes in BST
        Node* highestRating(Node *n); // find highest rated movie given prefix Node
        Node* getNodeFor(string a, Node *n) const; // get Node for prefix given
        Node* prefixNodesBST(string a, Node *n); // find Node that contains given prefix
        Node *root;
    private:
        void clear(Node *n); // for destructor
        int depth(Node* n) const; // check depth of Node
        void printPreOrderHelper(Node *n) const; // recursive helper for printing pre-order
        void searchAllNodesHelper(Node*n) const; // recursive helper to search through all Nodes
        bool insertHelper(string a, double b, Node *n); // recursive helper for insert
        int n_visitedHelper(string a, Node *n) const; // recursive helper for counting number of Nodes visited
        int countNodesHelper(Node *n) const; // recursive helper for counting total number of Nodes in BST
        Node* highestRatingHelper(Node *n); // recursive helper for finding the highest rating
        Node* prefixNodeBSTHelper(string a, BST *s, Node *n); // recursive helper for finding prefix Node
};

#endif