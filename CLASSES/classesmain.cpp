#include <iostream>
#include <vector>
#include "Media.h"
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"
using namespace std;

//Function prototypes
void addMedia(vector<Media*> &Vec);
void searchMedia(vector<Media*> Vec);
void deleteMedia(vector<Media*> &Vec);

int main(){
    //creating variables
    char input[100];
    vector<Media*> Vec;
    
    // keeps running program until user quits
    while ( (strcmp(input, "QUIT") != 0)) {
      
        cout << "\nEnter a command (ADD, SEARCH, DELETE, QUIT)\n";
	cin >> input;

        if (strcmp(input, "ADD") == 0) {
	  addMedia(Vec);
        }
        if (strcmp(input, "SEARCH") == 0) {
	  searchMedia(Vec);
	}
       if (strcmp(input, "DELETE") == 0) {
	  deleteMedia(Vec);
	}
    }
}

void addMedia(vector<Media*> &Vec) {
  char type[100];

  cout << "\nEnter type of media: VIDEOGAMES, MUSIC, MOVIES\n";
  cin >> type;
	    
  if (strcmp(type, "VIDEOGAMES") == 0) {
    VideoGames* newG = new VideoGames();
    Vec.push_back(static_cast<Media*>(newG));
  }
  if (strcmp(type, "MUSIC") == 0) {
    Music* newMu = new Music();
    Vec.push_back(static_cast<Media*>(newMu));
  }
  if (strcmp(type, "MOVIES") == 0) {
    Movies* newM = new Movies();
    Vec.push_back(static_cast<Media*>(newM));
  }
}

void searchMedia(vector<Media*> Vec) {
  char search[200];
  int year;

  cout << "\nSearch by TITLE or YEAR? \n";
  cin >> search;

  if (strcmp(search, "TITLE") == 0 ) {
    cout << "Enter the TITLE \n";
    cin >> search;
    
    for (vector<Media*>::iterator i = (Vec).begin(); i != (Vec).end(); ++i) {
      if (strcmp((*i)->getTitle(), search) == 0) {
	(*i)->printInfo();
      }    
    }
  }
  if (strcmp(search, "YEAR") == 0 ) {
    cout << "Enter the YEAR \n";
    cin >> year;
    
    for (vector<Media*>::iterator i = (Vec).begin(); i != (Vec).end(); ++i) {
      if ((*i)->getYear() == year) {
	(*i)->printInfo();
      }    
    }
  }
}

void deleteMedia(vector<Media*> &Vec) {
  char search[200], check[10];
  int year, j=0;

  cout << "\nDelete by TITLE or YEAR? \n";
  cin >> search;

  if (strcmp(search, "TITLE") == 0 ) {
    cout << "Enter the TITLE \n";
    cin >> search;

    for (vector<Media*>::iterator i = (Vec).begin(); i != (Vec).end(); ++i, j++) {
      if (strcmp((*i)->getTitle(), search) == 0) {
	
	cout << "\n Confirm you would like to delete the following. Enter Y or N\n";
	(*i)->printInfo();
	cin >> check;
	
	if (strcmp(check, "Y") == 0) {
	  Vec.erase(Vec.begin()+j);
	  break;
	}
      }    
    }
  }
    
  if (strcmp(search, "YEAR") == 0 ) {
    cout << "Enter the YEAR \n";
    cin >> year;

    for (vector<Media*>::iterator i = (Vec).begin(); i != (Vec).end(); ++i, j++) {
      if ((*i)->getYear() == year) {
	
	cout << "\n Confirm you would like to delete the following. Enter Y or N\n";
	(*i)->printInfo();
	cin >> check;
	
	if (strcmp(check, "Y") == 0) {
	  Vec.erase(Vec.begin()+j);
	  break;
	}   
      }
    }
  }
}

