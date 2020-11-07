#include <iostream>
#include <string.h>
#include "Student.h"
#include "Node.h"

using namespace std;

Student* AddStudent();
void PrintAll();
void AddNode();

Node *head = NULL, *tail = NULL;

int main() {
  
  char command[6];
  command[0]=0;
  
  while (strcmp (command,"QUIT") != 0) {
    cout << "\nEnter one of the following commands: ADD, PRINT, DELETE, QUIT \n";
    cin >> command;
    
    if (strcmp (command,"ADD") == 0) {
      AddNode();}
    if (strcmp (command,"PRINT") == 0) {
      PrintAll(); }  
  }
  return 0;
}

  
 Student* AddStudent() {
    Student *newStud;
    //new alwasy returns a pointer
    newStud = new Student;
    newStud->readStudentInfo();
    return newStud;
  }

void AddNode(){
  Node *newN, *curN;
  newN = new Node(AddStudent());
  if (head == NULL) {
    head = newN;
    newN->setNext(NULL);
    // cout << newN->getStudent()->getFirstname() << "\n";
  }
  else {
    if (head != NULL) {
      curN = head;
      while (curN->getNext()!=NULL){
	curN = curN->getNext();
      }
      curN->setNext(newN); 
      cout << "head not NULL";
    }
  }
}

void PrintAll() {
  Node *curN;
  curN = head;
  while (curN != NULL) {
    cout << "{" << curN->getStudent()->getFirstname() << " " << curN->getStudent()->getLastname()<< " } \n" ;
    curN = curN->getNext();
  }    

}
