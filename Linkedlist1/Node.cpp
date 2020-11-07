#include <iostream>
#include <string.h>
#include "Node.h"


using namespace std;

Node::Node(Student* newStudPtr) {
  Next = NULL;
  StudPtr = newStudPtr; 
}

Node::~Node() {
  Next = NULL;
  //couldn't leave it blank so set Next=NULL
}

Student* Node::getStudent(){
  return StudPtr;
}

Node* Node::getNext(){
  return Next;
}

void Node::setNext(Node* newNext) {
  Next = newNext;
    }


