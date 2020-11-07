#include <iostream>
#include <string.h>
#include "Student.h"

using namespace std;

Student::Student () {
  Firstname = "";
  Lastname = "";
  ID = 0;
  GPA = 0;
  // Next = NULL;
}
Student::~Student () {
  ID = 0;
}

string Student::getFirstname(){
  return Firstname;
}
string Student::getLastname(){
  return Lastname;
}
int Student::getID(){
  return ID;
}
float Student::getGPA(){
  return GPA;}

void Student::readStudentInfo()  {
  cout << "\nEnter first name \n";
  cin >> Firstname;
  cout << "\nEnter last name \n";
  cin >> Lastname;
  cout << "\nEnter ID number \n";
  cin >> ID;
  cout << "\nEnter GPA \n";
  cin >> GPA;
}

