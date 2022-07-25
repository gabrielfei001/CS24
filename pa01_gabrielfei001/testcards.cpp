// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_append();
  test_equal();
  test_card();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  START_TEST("test_search");
  test_search();
  START_TEST("test_remove");
  test_remove();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
  string testname = "Append into Empty List test";
  CardList c2;
  Card *c = new Card('d', '4');
  c2.append(c);
  
  assertEquals(c2.head, c2.tail, testname);
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)

}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  CardList l1, l2;
  assertEquals(l1.head,l2.head, testname);
}

void test_card_operator_double_equal(){
  string testname = "Check if cards are Equal";
  Card h('d', '3');
  Card j('d', '3');
  assertEquals(j, h, testname);
}

void test_search() {
  CardList c1, c2;
  Card *a = new Card('h', '3');
  string testname = "Search for card in CardList";
  c1.append(a);
  assertEquals(('h', '3'), (a->suit, a->value), testname);
}

void test_remove() {
  string testname = "Remove a card in CardList";
  CardList c3, c4;
  c3.append(new Card('h', '3'));
  c3.remove(1);
  assertEquals(c3.head, c4.head, testname);
}
