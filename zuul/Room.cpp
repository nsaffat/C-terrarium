#include <iostream>
#include <string.h>
//#include <stdio.h>
#include <vector>
#include <iterator>
#include "Room.h"

using namespace std;

Room::Room(){
  RoomID = 0;
  NorthExit = NULL;
  SouthExit = NULL;
  WestExit = NULL;
  EastExit = NULL;
}
Room::~Room(){
  RoomID = 0;
}


int Room::getRoomID(){
  return RoomID;
}
Room* Room::getNorthExit(){
  return NorthExit;
}
Room* Room::getSouthExit(){
  return SouthExit;
}
Room* Room::getEastExit(){
  return EastExit;
}
Room* Room::getWestExit(){
  return WestExit;
}

vector<Item*> Room::getItemList(){
  return ItemList;
  }


void Room::setRoomID(int newID){
  RoomID = newID;
}
void Room::setNorthExit(Room* newNorth){
  NorthExit = newNorth;
}
void Room::setSouthExit(Room* newSouth){
  SouthExit = newSouth;
}
void Room::setWestExit(Room* newWest){
  WestExit = newWest;
}
void Room::setEastExit(Room* newEast){
  EastExit = newEast;
}

void Room::addItem(Item* newItem){
  ItemList.push_back(newItem);
}


void Room::removeItem(const char* nameItem){
  int j=0;
  for (vector<Item*>::iterator i = ItemList.begin(); i != ItemList.end(); ++i,j++) {
    if (strcmp ((*i)->name,nameItem) == 0)  {
      ItemList.erase(ItemList.begin()+j);
      break;
    }
  }
}
void Room::removeAllItem() {
  int j=0;
  /*
  for (vector<Item*>::iterator i = ItemList.begin(); i != ItemList.end(); ++i,j++) {
    cout << "In removeAllItem\n";
    ItemList.erase(ItemList.begin()+j);
 }
  */

  ItemList.clear();

}

void Room::printItems() {
  for (vector<Item*>::iterator i = ItemList.begin(); i != ItemList.end(); ++i) {
    cout << (*i)->name << "  ";
  }
  if (ItemList.size()==0) {
    cout << "NO ITEMS IN ROOM";
  }
}

void Room::printExits() {
  if ( NorthExit != NULL ){
    cout << " NORTH ";
  }
  if ( SouthExit != NULL ){
    cout << " SOUTH ";
  }
  if ( WestExit != NULL ){
    cout << " WEST ";
  }
  if ( EastExit != NULL ){
    cout << " EAST ";
  }
  cout << "\n"; 
}


