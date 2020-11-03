#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

//info abt vectors/iterators https://www.bitdegree.org/learn/c-plus-plus-vector#how-to-create-c-vectors
//struct is a value type, so can replace int with Frame in  the example code from your Value Reference Pointers video


struct Frame {char firstname[10]; char lastname[10]; int id; float gpa; };
vector <Frame*> Vec1;

//function prototypes
void Add(vector<Frame*> &Vec1);
void Print(vector<Frame*> &Vec1);
void Delete(vector<Frame*> &Vec1);


int main () {
  char command[6];

  while (strcmp (command,"QUIT") != 0) {
    cout << "\nEnter one of the following commands: ADD, PRINT, DELETE, QUIT \n";
    cin >> command;

    if (strcmp (command,"ADD") == 0) {
      Add(Vec1); }
  
    if (strcmp (command,"PRINT") == 0) {
      Print(Vec1); }
  
    if (strcmp (command,"DELETE") == 0) {
      Delete(Vec1); }
  }
    return 0;
  }

void Add(vector<Frame*> &Vec1){
  //forward declaration for unnamed struct
  Frame* P =  new Frame;
  cout << "\nEnter first name \n";
  cin >> (*P).firstname;
  cout << "\nEnter last name \n";
  cin >> (*P).lastname;
  cout << "\nEnter ID number \n";
  cin >> (*P).id;
  cout << "\nEnter GPA \n";
  cin >> (*P).gpa;
  Vec1.push_back(P);
}

// used example from https://www.oreilly.com/library/view/c-cookbook/0596007612/ch06s05.html
void Print(vector<Frame*> &Vec1)  {
  for (vector<Frame*>::iterator i = Vec1.begin(); i != Vec1.end(); ++i){
    cout << (*i)->firstname << " " << (*i)->lastname << ", " << (*i)->id << ", " << (*i)->gpa << endl;
 }
}

void Delete(vector<Frame*> &Vec1) {
  int number;
  cout << "What is the ID number of the student you want to delete? \n";
  cin >> number;

  for (vector<Frame*>::iterator i = Vec1.begin(); i != Vec1.end(); ++i) {
    //why can't the value retrived from the struct be read as an int?
    if ( (*i)->id == number) {
      Vec1.erase(Vec1.begin() + i);
      break; }
  }
}


