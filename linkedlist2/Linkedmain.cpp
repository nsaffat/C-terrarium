#include <iostream>
#include <string.h>
#include "Student.h"
#include "Node.h"
#include <iomanip>  //library to print float to 2 digits http://www.cplusplus.com/reference/ios/fixed/


using namespace std;

Student* AddStudent();
void Print(Node* temp);
void AddNode(Node* &head);
void Delete(Node* &head);
void Average(Node* temp);

int main() {
  Node *head = NULL;
  
  char command[15];
  command[0]=0;
  
  while (strcmp (command,"QUIT") != 0) {
    command[0]=0;
    cout << "\nEnter one of the following commands: ADD, PRINT, DELETE, QUIT, AVERAGE \n";
    cin >> command;
    
    if (strcmp (command,"ADD") == 0) {
      AddNode(head);}
    
    if (strcmp (command,"PRINT") == 0) {
      Print(head); }  

    if (strcmp (command,"DELETE") == 0) {
      if (head != NULL) {
	Delete(head);
      }
      else {
	cout << "\nThere are no students to delete";
      }
    }
    if (strcmp (command,"AVERAGE") == 0) {
      Average(head);
    }
  }
  return 0;
}

  
Student* AddStudent() {
    Student *newS;
    newS = new Student;
    newS->readStudentInfo();
    return newS;
  }

void AddNode(Node* &head){
  Node *newN, *temp;
  //constructer for Node needs ptr to its Student. The AddStudent() returns a ptr to new Student
  newN = new Node(AddStudent());
  //if statement for empty  list
  if (head == NULL) {
    head = newN;
    newN->setNext(NULL);
    //Delete(head);
  }
  //else statement to add node to existing linked list
  else {
    temp = head;
    while (temp->getNext()!=NULL){
      temp = temp->getNext();
    }
    temp->setNext(newN); 
  }
}

void Delete(Node* &head) {
  int ID;
  Node *temp;

  cout << "\nEnter ID of student you want to delete \n";
  cin >> ID;

  temp = head;  
  //code to delete the head node, must reassign head value
  if (temp->getStudent()->getID() == ID) {
    head = head->getNext();
    delete temp;
    return;
  }
  
  //code to delete non-head nodes
  while (temp != NULL){
    if (temp->getNext()->getStudent()->getID() == ID) {
      temp->setNext( temp->getNext()->getNext() );
      delete temp->getNext();
    }   
    temp = temp->getNext();
  }
}

void Print(Node* temp) {
  if (temp != NULL) {
    cout << setprecision(2) << fixed; //this prints GPA to 2 dgits
    //prints info for 1 node/student
    cout << "{" << temp->getStudent()->getFirstname() << " " << temp->getStudent()->getLastname()<< ", " <<  temp->getStudent()->getID() << ", " <<  temp->getStudent()->getGPA() << "} \n" ;
    //calls Print again for next node
    Print( temp->getNext() );
  }    
}

void Average(Node* temp) {
  float sum = 0.0;
  int count = 0;

  //for every node in the list, add the GPA to sum of GPAs, add 1 to the count of students, set temp to next
  while (temp != NULL){
    sum = sum + temp->getStudent()->getGPA();
    count = count + 1;
    temp = temp->getNext();
  }
  cout << setprecision(2) << fixed; //this prints GPA to 2 dgits
  cout << "\nAverage GPA is " << (sum/count);
}
