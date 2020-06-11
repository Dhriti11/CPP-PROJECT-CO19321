//function to input information
//function to configure medical condition
// function to add the condition pirority and the pain level
//add condition to maxheap
//function to output estimated appointment time
//--------------------------------------------------------------------------------------------------------------//

#include <string> //to do string operations 
#include <iostream> //to include standard i/o functions and maniuplators etc
#include <fstream> // for file related functions 
#include <set>//defines set and multiset container classes 
#include <vector> 
#include <queue> 
using namespace std; 


struct condition;

struct symptom
{
    string name;
    set<condition*> conditions;
    symptom* next = 0;
};

struct condition
{
  string name;
  int priority;
  float percentage=0;
  set <symptom*> symptoms;
  condition* next = 0;
};
//operator overload

struct patient{
  string name;
  set<symptom*> symptoms;
  condition* condition;
  int pain;
  int totalP; // total priority, priority of the disease plus the pain level
};

class Compare1
{
public:
    bool operator() (condition* v1, condition* v2)
    {
        return v1->percentage > v2->percentage;
    }
};

class Compare2
{
public:
    bool operator() (patient* v1, patient* v2)
    {
        return v1->totalP > v2->totalP;
    }
};



class Conditions {// AKA diseases
private:
  int ChashFunction(string word);//WORKS
  int ShashFunction(string word);//WORKS


public:
  Conditions(int ChashTableSize, int ShashTableSize);
  ~Conditions();

  void menu();
  void menu1();
  void menu2();

  condition** ChashTable;
  int ChashTableSize;
  void readFile(string file);
  condition* Cadd(string name, int priority, set<symptom*> symptoms);//WORKS


  symptom** ShashTable;
  int ShashTableSize;
  void Sadd(symptom* sympt);//WORKS
  void assignOrder();
  condition* searchCondition(string name);
  void printSymptoms();
  symptom* searchSymptom(string name);
  symptom**  accessSymptom(string name);
  void resetPercentage();

  patient* thepatient=0;
  void createPatient();
  set<symptom*> getIntersection(set<symptom*> set1, set<symptom*> set2);
  set<condition*> getUnion(set<condition*> set1, set<condition*> set2);
  float getPercentage(set<symptom*> intersect);
  void analyzeMatchedConditions(priority_queue<condition*, std::vector<condition*>, Compare1> Q);
  priority_queue<condition*, std::vector<condition*>, Compare1> getBestMatchConditions();
  void writeDescription();//WORKS

  priority_queue<patient*, vector<patient*>, Compare2> queue1;
  void treatPatient();
  void addPatienttoqueue();
  void updateQueue();
  void printOrder();
  void printConditions();

  void system();


};

// BUILDING THE SYMPTOMS/CONDITION LIBRARY
///////

// read symptoms/condition(name) file into vector set.
//read condition/priority file into vector of structs(which includes the description of the condiation and pirority)

///////

