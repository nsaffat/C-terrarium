#pragma once
#include "Media.h"
#include <iostream>
#include <string>

class Movies : public Media {
public:
   Movies();
  ~Movies();
  
  virtual char* getDirector();
  virtual int getRating();
  virtual int getDuration();
  virtual void printInfo();

  int duration;
  char* director;
  int rating;
};
