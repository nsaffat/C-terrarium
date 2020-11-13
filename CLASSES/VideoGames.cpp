#include "VideoGames.h"

//Constructer reads user input
VideoGames::VideoGames() {
  publisher = new char();
  int inputInt;
  
  cout << "\nEnter the title of the video game ";
  cin >> title;
  
  cout << "Enter the year the video game was made ";
  cin >> inputInt;
  year = inputInt;
    
  cout << "Enter the publisher of the video game ";
  cin >> publisher;
    
  cout << "Enter the rating of the video game  ";
  cin >> inputInt;
  rating = inputInt;
}

VideoGames::~VideoGames() {
    delete title;
    delete publisher;
}


char* VideoGames::getPublisher() {
    return publisher;
}
int VideoGames::getRating() {
    return rating;
}

void VideoGames::printInfo() {
    cout << "\nTitle: " << getTitle() << ", Year:  " << getYear() << ", Publisher: " << getPublisher() << ", Rating: " << getRating() << "\n";
}



