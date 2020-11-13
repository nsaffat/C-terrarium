#pragma once
#include <iostream>
#include "Media.h"

using namespace std;

class VideoGames : public Media {
public:
  VideoGames();
  ~VideoGames();
  
  virtual char* getPublisher();
  virtual int getRating();
  virtual void printInfo();

  char* publisher;
  int rating;
};
