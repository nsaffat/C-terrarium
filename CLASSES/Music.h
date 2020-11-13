#pragma once
#include "Media.h"
#include <iostream>
#include <string>

using namespace std;

class Music : public Media {
public:
  Music();
  ~Music();
  
  virtual char* getPublisher();
  virtual char* getArtist();
  virtual int getDuration();
  virtual void printInfo();

  int duration;
  char* publisher;
  char* artist;
};
