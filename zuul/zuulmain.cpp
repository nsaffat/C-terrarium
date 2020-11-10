#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "Room.h"

using namespace std;

//struct Item {char name[10]; int room;};

Item* totalItems[5]; //makes array of pointers for total Items in the game
Room *RoomPtr[15];



//function prototypes
Room* createMap(); //creates map and saves the Ptr of Room 0
void createItems(); //assigns every item to a room
void printItems();  //prints all items in player inventory
void pickItem(char nameItem);
void dropItem(char nameItem);
void printRoom(Room* Ptr); //prints the room #, items in the room, possible exits
Room* moveRoom(Room* Ptr);
int returnRoomID();
bool CheckWin();


int main(){
  char command[6];
  vector <Item*> ItemInventory; //vector for player inventory
  Room *currRoom = NULL, *tR; //Room that player is located in
  currRoom = createMap();  
  createItems();

  //  for (int p=0; p<15; p++){  
  //  printRoom(RoomPtr[p]); }

  cout << "\nWelcome Player X to the Saffat House of Horrors. To win the game you must pick up all 5 items hidden in the map and then drop them in Room 0. \n";
  
  while (CheckWin()==0){
 
    printRoom(currRoom);
    /*
    cout << "Choose what you want to do: PICK DROP MOVE QUIT\n";
    cin >> command;

    if (strcmp (command,"MOVE") == 0) {
      currRoom = moveRoom(currRoom);
      cout << "\nIn main func " << currRoom;
    }
    if (strcmp (command,"QUIT") == 0) {
      break;
    }
    */

    tR =  currRoom->getNorthExit();    
    if(tR!=NULL) printRoom(tR);
    tR =  currRoom->getSouthExit();    
    if(tR!=NULL) printRoom(tR);
    tR =  currRoom->getEastExit();    
    if(tR!=NULL) printRoom(tR);
    tR =  currRoom->getWestExit();    
    if(tR!=NULL) printRoom(tR);

    currRoom = currRoom->getNorthExit();
    tR =  currRoom->getNorthExit();    
    if(tR!=NULL) printRoom(tR);
    tR =  currRoom->getSouthExit();    
    if(tR!=NULL) printRoom(tR);
    tR =  currRoom->getEastExit();    
    if(tR!=NULL) printRoom(tR);
    tR =  currRoom->getWestExit();    
    if(tR!=NULL) printRoom(tR);
  
    break;

  }
  return 0;
}


bool CheckWin() {
  return 0;
}

Room* moveRoom(Room* cR) {
  char direction[5];
  
  cout << "\nWhich direction do you want to move?\n";
  cin >> direction;
  
  if (strcmp (direction,"NORTH") == 0) {
    cR = cR->getNorthExit();
    cout << "\nMoved  " << cR;
  }
  return cR;
}

void printRoom(Room* currRoom) {
  cout << "\nYou are currently in Room " << currRoom->getRoomID();
  cout << "\nThe objects in this room are ";
  
  /* for (int i=0; i<5; i++) {
    if ( totalItems[i]->room == currRoom->getRoomID()) {
      cout << totalItems[i]->name << "  ";
      }
      }*/
  
  currRoom->printItems();
  cout << "\nThe exits from this room are ";
  currRoom->printExits();
  cout << "\n";
}





void createItems() {
  
  for (int i=0; i<5; i++) {
    totalItems[i] =  new Item;
  }

  strcpy( (totalItems[0]->name), "EYEBALL");  
  (*totalItems[0]).room = 8;
  RoomPtr[8]->addItem(totalItems[0]);
 
  strcpy( (totalItems[1]->name), "KNIFE");    
  (*totalItems[1]).room = 2;
  RoomPtr[2]->addItem(totalItems[1]);
  
  strcpy( (totalItems[2]->name), "MIRROR");  
  (*totalItems[2]).room = 14;
  RoomPtr[14]->addItem(totalItems[2]);

  strcpy( (totalItems[3]->name), "RING");  
  (*totalItems[3]).room = 5;
  RoomPtr[5]->addItem(totalItems[3]);

  strcpy( (totalItems[4]->name),  "FINGER");  
  (*totalItems[4]).room = 12;
  RoomPtr[12]->addItem(totalItems[4]);

}


Room* createMap() {
  //creating 15 rooms
  int i=0;
  for (i=0; i<15; i++) {
    RoomPtr[i] =  new Room;
    RoomPtr[i]->setRoomID(i);
    RoomPtr[i]->setNorthExit(NULL);
    RoomPtr[i]->setSouthExit(NULL);
    RoomPtr[i]->setEastExit(NULL);
    RoomPtr[i]->setWestExit(NULL);
    cout << "Room Ptr " << RoomPtr[i] << "\n"; 
  }

  //setting the current Room pointer (declared in Main) to the adress of the first room. Will be used in main function
  //currRoom =  RoomPtr[0];

  //assigning Room pointers to exits. Ignore this part

  //RoomPtr[0]->setNorthExit(RoomPtr[6]);
  
  RoomPtr[0]->setNorthExit(RoomPtr[6]);
  RoomPtr[0]->setSouthExit(RoomPtr[9]);
  RoomPtr[0]->setWestExit(RoomPtr[12]);
  RoomPtr[0]->setEastExit(RoomPtr[2]);
  
  RoomPtr[1]->setSouthExit(RoomPtr[2]);
  
  RoomPtr[2]->setNorthExit(RoomPtr[1]);
  RoomPtr[2]->setSouthExit(RoomPtr[4]);
  RoomPtr[2]->setEastExit(RoomPtr[3]);
  RoomPtr[2]->setWestExit(RoomPtr[0]);

  RoomPtr[3]->setWestExit(RoomPtr[2]);

  RoomPtr[4]->setNorthExit( RoomPtr[2]);

  RoomPtr[5]->setEastExit( RoomPtr[6]);

  RoomPtr[6]->setEastExit( RoomPtr[7]);
  RoomPtr[6]->setWestExit( RoomPtr[5]);  RoomPtr[6]->setSouthExit( RoomPtr[0]);
  RoomPtr[7]->setWestExit(RoomPtr[6]);
  RoomPtr[8]->setEastExit( RoomPtr[9]);
  RoomPtr[9]->setEastExit( RoomPtr[10]);   RoomPtr[9]->setWestExit( RoomPtr[8]);  RoomPtr[9]->setNorthExit( RoomPtr[0]);
  RoomPtr[10]->setWestExit(RoomPtr[9]);
  RoomPtr[11]->setNorthExit( RoomPtr[12]);
  RoomPtr[12]->setNorthExit(RoomPtr[13]);   RoomPtr[12]->setSouthExit(RoomPtr[11]);  RoomPtr[12]->setWestExit(RoomPtr[14]);  RoomPtr[12]->setEastExit(RoomPtr[0]);
  RoomPtr[13]->setSouthExit(RoomPtr[12]);
  RoomPtr[14]->setEastExit( RoomPtr[12]);
  */
  
  return RoomPtr[0];
}
