#include <iostream>
#include <string.h>
#include "Node.h"


using namespace std;

Node::Node(Student* newStud) {
  Next = NULL;
  Stud = newStud; 
}

Node::~Node() {
  Next = NULL;
  //couldn't leave it blank so set Next=NULL
}

Student* Node::getStudent(){
  return Stud;
}

Node* Node::getNext(){
  return Next;
}

void Node::setNext(Node* newNext) {
  Next = newNext;
    }


