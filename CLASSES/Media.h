#pragma once
#include <iostream>
#include <string>

using namespace std;
class Media {
public:
  //functions:
  virtual char* getTitle();
  virtual int getYear();
  virtual void printInfo();
  Media();

  char* title;
  int year;
  bool checked;
};
