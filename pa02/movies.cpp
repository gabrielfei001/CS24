// movies.cpp
// Anika Arora, Gabriel Fei
// 5/29/20

#include <time.h>
#include <iostream>
#include "movies.h"
#include "utility.h"
 
using namespace std;

Node::~Node() {
    name = "";
    rating = 0.0;
    left = 0;
    right = 0;
    parent = 0;
}

BST::BST() {
    root = 0;
}

BST::~BST() {
    clear(root);
}

void BST::clear(Node *n) {
    if(n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

bool BST::insert(string a, double b) {
    if(!root) {
        root = new Node(a, b);
        return true;
    }
    insertHelper(a, b, root);
}

bool BST::insertHelper(string a, double b , Node *n) {
    if(a == n->name) {
        return false;
    }
    if(a < n->name) {
        if(n->left) {
            return insertHelper(a, b, n->left);
        }
        else {
            n->left = new Node(a, b);
            n->left->parent = n;
            return true;
        }
    }
    else {
        if(n->right) {
            return insertHelper(a, b, n->right);
        }
        else {
            n->right = new Node(a, b);
            n->right->parent = n;
            return true;
        }
    }
}

int BST::depth(Node *n) const{
    int x = 0;
    Node *p = n;
    while(p->parent) {
        x++;
        p = p->parent;
    }
    return x;
}

void BST::printPreOrder() const {
    printPreOrderHelper(root);
}

void BST::printPreOrderHelper(Node *n) const {
    if (!n) {
        return;
    }
    cout << n->name << ", " << n->rating << ", " << depth(n) << endl;
    printPreOrderHelper(n->left);
    printPreOrderHelper(n->right);
}

Node* BST::getNodeFor(string a, Node* n) const {
    if(!n) {
        return NULL;
    }
    if(n == NULL || n->name == a) {
        return n;
    }
    if(n->name < a) {
        return getNodeFor(a, n->right);
    }
    return getNodeFor(a, n->left);
}

void BST::search(BST& p, int W, string a){
    double N = p.countNodes();
    double NW = N * W;
    clock_t t;
    double *average = new double[W];
    for (int i = 0; i < W; i++) {
        t = clock();
        p.printPreOrder(); 
        t = clock()-t;
        average[i] = (((double)t)/(CLOCKS_PER_SEC)) * 1000000/N;
    }
    cout << "Minimum Average Time is: " << min(average, W) << " micro seconds." << endl;
    cout << "Maximum Average Time is: " << max(average, W) << " micro seconds." << endl;
    cout << "Median Average Time is: " << med(average, W) << " micro seconds." << endl;
    delete average;
}

Node* BST::highestRating(Node *n) {
    Node *high = n;
    return highestRatingHelper(n);
}

Node* BST::highestRatingHelper(Node *n) {
    Node *high = n;
    if(n->left) {
        Node *lhigh = highestRatingHelper(n->left);
        if(high->rating < lhigh->rating) {
            high = lhigh;
        }
    }
    if(n->right) {
        Node *rhigh = highestRatingHelper(n->right);
        if(high->rating < rhigh->rating) {
            high = rhigh;
        }
    }
    return high;
}

Node* BST::prefixNodesBST(string a, Node *n) {
    BST* s = new BST;
    return prefixNodeBSTHelper(a, s, n);
}

Node* BST::prefixNodeBSTHelper(string a, BST *s, Node *n) {
    if(n) {
        if(n->name.substr(0, a.length()) == a) {
            s->insert(n->name, n->rating);
        }
        prefixNodeBSTHelper(a, s, n->left);
        prefixNodeBSTHelper(a, s, n->right);
    }
    return s->root;
}

int BST::n_visited(string a) const {
    return n_visitedHelper(a, root);
}

int BST::n_visitedHelper(string a, Node *n) const {
    if(!n) {
        return -1;
    }
    if(n->name == a) {
        return 0;
    }
    else if(n->name > a) {
        return n_visitedHelper(a, n->left) + 1;
    }
    else {
        return n_visitedHelper(a, n->right) + 1;
    }
}

int BST::countNodes() const {
    return countNodesHelper(root);
}

int BST::countNodesHelper(Node *n) const {
    if(!n) {
        return 0;
    }
    return countNodesHelper(n->left) + countNodesHelper(n->right) + 1;
}

void BST::searchAllNodes() const {
    searchAllNodesHelper(root);
}

void BST::searchAllNodesHelper(Node*n) const {
    if(!n) {
        return;
    }
    searchAllNodesHelper(n->left);
    searchAllNodesHelper(n->right);
}