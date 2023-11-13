#include "BST.h"
#include "linked.h"

#include <iostream>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;


// functions to automate randomizing
void getRandoms(int n, mt19937 gen32, int*& randoms){
  delete[] randoms;
  randoms = new int[n];
  for(int i = 0; i < n; ++i){
    randoms[i] = gen32() % 1000;
  }
}



void timeBST(int n, int* randoms, BST &b){

  // time recording block
  const auto start = chrono::high_resolution_clock::now();
  
  for(int i = 0; i < n; i++) b.insert(randoms[i]);


  const auto end = chrono::high_resolution_clock::now();

  const chrono::duration<double> elapsed_seconds = end - start;

  cout << "linked insert time: " << elapsed_seconds.count() << endl;
}



void timeLinked(int n, int* randoms, Linked &l){
  
  // time recording block
  auto start = chrono::high_resolution_clock::now();
  
  for(int i = 0; i < n; ++i) l.append(randoms[i]);
   
  auto end = chrono::high_resolution_clock::now();
  

  chrono::duration<double> elapsed_seconds = end - start;

  cout << "BST insert time: " << elapsed_seconds.count() << endl;
}
void timeSearchBST(int query, BST b){
  auto start = chrono::high_resolution_clock::now();
  
  b.find(query);
   
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double> elapsed_seconds = end - start;

  cout << "time to search BST: " << elapsed_seconds.count() << endl;
}
void timeSearchLinked(int query, Linked l){
  auto start = chrono::high_resolution_clock::now();
  
  l.find(query);
   
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double> elapsed_seconds = end - start;

  cout << "time to search Linked List: " << elapsed_seconds.count() << endl;
}



void runAll(int n, int* randoms, mt19937 gen32){
    

    cout << "testing with random numbers in range: " << n << endl << endl;
    getRandoms(n, gen32, randoms);
    BST binary = BST();
    Linked linked = Linked();
    timeBST(n, randoms, binary);
    timeLinked(n, randoms, linked);

    cout << endl;
    for(int i = 0; i < 10; i++){
      

      int query = randoms[gen32() % n];

      timeSearchBST(query, binary);
      timeSearchLinked(query, linked); 

      cout << endl;
    }
}

int main()
{
  // random gererator
  mt19937 gen32;
  gen32.seed(chrono::system_clock::now().time_since_epoch().count());
  int* randoms = new int[1];

  

  runAll(1000, randoms, gen32);
  runAll(200, randoms, gen32);
  runAll(24, randoms, gen32);
  runAll(12, randoms, gen32);

  BST b = BST();
  // time recording block
  auto start = chrono::high_resolution_clock::now();
  
  for(int i = 1000; i > 0; i--){
    b.insert(i);
  }
   
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double> elapsed_seconds = end - start;

  cout << "time to insert 1000 - 1 BST: " << elapsed_seconds.count() << endl;
  b = BST();
  // time recording block
  start = chrono::high_resolution_clock::now();
  
  for(int i = 0; i < 1000; ++i){
    b.insert(i);
  } 
   
  end = chrono::high_resolution_clock::now();

  elapsed_seconds = end - start;

  cout << "time to insert 1 - 1000 BST: " << elapsed_seconds.count() << endl;

  Linked l = Linked();

  // time recording block
  start = chrono::high_resolution_clock::now();
  
  for(int i = 1000; i > 0; i--){
    b.insert(i);
    l.append(i);
  }
   
  end = chrono::high_resolution_clock::now();

  elapsed_seconds = end - start;

  cout << "time to insert 1000 - 1 Linked: " << elapsed_seconds.count() << endl;
  
  l = Linked();
  // time recording block
  start = chrono::high_resolution_clock::now();
  
  for(int i = 0; i < 1000; ++i){
    b.insert(i);
    l.append(i);
  } 
   
  end = chrono::high_resolution_clock::now();

  elapsed_seconds = end - start;

  cout << "time to insert 1 - 1000 Linked: " << elapsed_seconds.count() << endl;

  
  return 0;
}

