#include "Movies.h"

Movies::Movies() {
    director = new char();
    char* input = new char();
    int inputInt;
    
    cout << "Enter the title of the movie ";
    cin >> title;
    
    cout << "Enter the director the movie was made by ";
    cin >> director;
    
    cout << "Enter the year the movie was made ";
    cin >> inputInt;
    year = inputInt;
    
    cout << "Enter the duration of the movie ";
    cin >> inputInt;
    duration = inputInt;
    
    cout << "Enter the rating of the movie ";
    cin >> inputInt;
    rating = inputInt;
}

char* Movies::getDirector() {
    return director;
}

int Movies::getRating() {
    return rating;
}

int Movies::getDuration() {
    return duration;
}

void Movies::printInfo() {
    cout << "Title: " << getTitle() << ", Director: " << getDirector() << ", Year: " << getYear() << ", Duration: " << getDuration() << ", Rating: " << getRating() << endl;
}

Movies::~Movies() {
    delete title;
    delete director;
}
