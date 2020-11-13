#include "Music.h"

//constructer reads user input
Music::Music() {
    publisher = new char();
    artist = new char();
    int inputInt;
    
    cout << "Enter the title of song ";
    cin >> title;
    
    cout << "Enter the artist ";
    cin >> artist;
    
    cout << "Enter the year the song was made ";
    cin >> inputInt;
    year = inputInt;
    
    cout << "Enter the duration of the song ";
    cin >> inputInt;
    duration = inputInt;
    
    cout << "Enter the publisher of the song ";
    cin >> publisher;

}

Music::~Music() {
    delete title;
    delete publisher;
    delete artist;
}

char* Music::getArtist() {
    return artist;
}

char* Music::getPublisher() {
    return publisher;
}

int Music::getDuration() {
    return duration;
}

void Music::printInfo() {
    cout << "\nTitle: " << getTitle() << ", Artist: " << getArtist() << ", Year: " << getYear() << ", Duration: " << getDuration() << ", Publisher: " << getPublisher() << "\n";
}

