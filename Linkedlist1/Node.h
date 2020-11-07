#include <iostream>
#include <string.h>

#ifndef STUDENT_H
#include "Student.h"
#endif

using namespace std;

class Node {
 private:
  Node *Next;
  Student *StudPtr;
  
 public:
  Node(Student*);
  ~Node(); 
  Student* getStudent();
  Node* getNext(); 
  void setNext(Node* nextPtr);
};

  
