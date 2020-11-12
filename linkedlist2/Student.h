#ifndef STUDENT_H
#define STUDENT_H
#endif

using namespace std;

class Student {
 private:
  string Firstname;
  string Lastname;
  int ID;
  float GPA;
  // Student *Next;
  
public:
  Student();
  ~Student();
  string getFirstname();
  string getLastname();
  int getID();
  float getGPA();

  /*
  int checkID(int ID);
  void printStudent();
  void setNextStudent();
  void removeStudent(); */
  
  void readStudentInfo();
 
};
