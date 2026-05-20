// heap.cpp
// Katelyn Hamel

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time

Heap::Heap(){ //default
}

Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  
  //add to vdata
   for (auto it = start; it != end; ++it) {
    vdata.push_back(*it);
  }
  
  //nothing in means its already good
  if (vdata.size() <= 1){
    return;
  }
  
  //creating new helper
  for (int i = vdata.size()/ 2 - 1; i >= 0; i--){
    
    heapify(i);
    
  }

  cout << "heap size after build: " << vdata.size() << "\n";
  for (int x : vdata) cout << x << " ";
  cout << "\n";
  

}

void Heap::heapify(int i){
  int n = vdata.size();
  //making a way to detect left and right children of index
  int smallest = i;
  int left = 2* i + 1;
  int right = 2* i +2;

  if (left < n && vdata[left] < vdata[smallest] ){
    smallest = left;
  }

  if (right < n && vdata[right] < vdata[smallest]){
    smallest = right;
  }

  if(smallest != i){
    //swapping
    int holder = 0;
    holder = vdata[i];
    vdata[i] = vdata[smallest];
    vdata[smallest] = holder;
    
    heapify(smallest);
  }

}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){

  vdata.push_back(value);
  int i = vdata.size()-1;
  

  //find where the new value should go
  while (i >0){

    int parent = (i-1)/2;


    if (vdata[i] < vdata[parent]){
      //swapping
      int holder = 0;
      holder = vdata[i];
      vdata[i] = vdata[parent];
      vdata[parent] = holder;

      i = parent;
    }
    else{
      break;
    }
  }


}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()){
    return;
  }
  //min is the front because its a min heap so we bring it to the back
  vdata[0] = vdata.back();
  vdata.pop_back();

  if (!vdata.empty()){
    heapify(0);
  }


}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata.front();
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.empty()) return true;

  else return false;
}
    