// intbst.cpp
// Implements class IntBST
// Gabriel Fei, 5/5/20

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (!n) {
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (!n) {
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (!n) {
        return 0;
    }
    return (n->info + sum(n->left) + sum(n->right));
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (!n) {
        return 0;
    }
    return 1 + count(n->left) + count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (!n) {
        return NULL;
    }
    if (n == NULL || n->info == value) {
        return n;
    }
    if (n->info < value) {
        return getNodeFor(value, n->right);
    }
    return getNodeFor(value, n->left);
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root) == NULL) {
        return false;
    }
    else {
        return true;
    }
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* z = getNodeFor(value, root);
    if (z == NULL) {
        return z;
    }
    Node* p = NULL;
    if (z->left) {
        z = z->left;
        while(z->right) {
            z = z->right;
        }
        p = z;
    }
    else {
        while(z->parent){
            if (z->parent->info < value) {
                p = z->parent;
                break;
            }
            else {
                z = z->parent;
            }
        }
    }
return p;
}
// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* q = getPredecessorNode(value);
    if (!q) {
        return 0;
    }
    else {
        return q->info;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* t = getNodeFor(value, root);
    if (!t) {
        Node* t = NULL;
        return t;
    }
    Node* x = NULL;
    if (t->right) {
        t = t->right;
        while (t->left) {
            t = t->left;
        }
        x = t;
    }
    else {
        while (t->parent) {
            if (t->parent->info > value) {
                x = t->parent;
                break;
            }
            else {
                t = t->parent;
            }
        }
    }
    return x;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* w = getSuccessorNode(value);
    if (!w) {
        return 0;
    }
    else {
        return w->info;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if(n == NULL) {
        return false;
    }
    Node* p = n->parent;
    if(n->left == NULL && n->right == NULL){ //leaf node
        if(n == root) {
            root = NULL;
        }
        else {
            if(p->left == n) {
                p->left = NULL;
            }
            else {
                p->right = NULL;
            }
        }
    }
    else if(n->left == NULL && n->right != NULL){ // node with right child
        if(n == root){
            root = n->right;
        }
        else {
            if(p->left == n) {
                p->left = n->right;
            }               
            else {
                p->right = n->right;
            }
        }
        n->right->parent = p;
        delete n;
    }
    else if(n->left != NULL && n->right == NULL){ // node with left child
        if(n == root){
            root = n->left;
        }
        else {
            if(p->left == n) {
                p->left = n->left;
            }
            else {
               p->right = n->left;
            }
        }
        n->left->parent = p;
        delete n;
    }
    else{ // two children
        int successor = getSuccessor(value);
        remove(successor);
        n->info = successor;
    }
    return true;
}
