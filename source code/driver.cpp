#include "Conditions.hpp"
#include <string>//this is for string functions.
#include <iostream>//for cin,cout,mainuplators like endl 
#include <fstream>//derived from iostream,include file functions ,open(),close()
#include <sstream>//to read and write from string
#include <set>//includes set and multiset associative container class
#include <vector>//includes vector (dynamic array)sequence container class
#include <queue> //data structure operating in FIFO 
#include <algorithm> //functions for processing containers
using namespace std;

int main(){
  Conditions C(10, 10);
  C.readFile("conditions.txt");
  C.system();
  priority_queue<patient*> queue;
  patient a;
  C.printConditions();
  C.printSymptoms();
  C.menu();
  cout<<"TEST SEARCH FUNCTION"<<endl;
  C.searchSymptom("nausea");
  C.searchCondition("lung cancer");
  C.printSymptoms();
  C.writeDescription();
  
  set<int> test;
  test.insert(1);
  test.insert(2);
  test.insert(3);
  set<int>::iterator i;
  for (i=test.begin(); i!=test.end(); ++i)
  {
    cout<<*i<<endl;
  }
  return 0;
}
