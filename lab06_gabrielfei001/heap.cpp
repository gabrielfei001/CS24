// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    int i = vdata.size();
    vdata.push_back(value);
    while(i != 0) {
      int parent = (i - 1) / 2;
      if(vdata[i] < vdata[parent]) {
        vdata[i] = vdata[parent];
        vdata[parent] = value;
        i = parent;
      }
      else {
        break;
      }
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  vdata[0] = vdata[vdata.size() - 1];
  vdata.erase(vdata.end() - 1);
  int i = 0;
  while(true) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if((left < vdata.size()) && (right < vdata.size())) {
      if((vdata[i] <= vdata[left]) && (vdata[i] <= vdata[right])) {
        break;
      }
      if(vdata[left] <= vdata[right]) {
        int t = vdata[i];
        vdata[i] = vdata[left];
        vdata[left] = t;
        i = left;
      }
      else {
        int t = vdata[i];
        vdata[i] = vdata[right];
        vdata[right] = t;
        i = right;
      }
    }
    else if((left >= vdata.size()) && (right >= vdata.size())) {
        break;
    }
    else {
      if((vdata[i] <= vdata[left]) && (vdata[i] <= vdata[right])) {
        break;
      }
      int t = vdata[i];
      vdata[i] = vdata[left];
      vdata[left] = t;
      i = left;
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size() == 0) {
    return true;
  }
  else{
    return false;
  }
}
    
