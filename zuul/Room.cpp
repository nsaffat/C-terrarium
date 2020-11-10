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


void Room::printItems() {
  for (vector<Item*>::iterator i = ItemList.begin(); i != ItemList.end(); ++i) {
    cout << (*i)->name << "  ";
  }
  if (ItemList.size()==0) {
    cout << "NONE";
  }
}

void Room::printExits() {
  if ( getNorthExit() != NULL ){
    cout << " NORTH ";
  }
  if ( getSouthExit() != NULL ){
    cout << " SOUTH ";
  }
  if ( getWestExit() != NULL ){
    cout << " WEST ";
  }
  if ( getEastExit() != NULL ){
    cout << " EAST ";
  }
  cout << "\n"; 
}

void Room::removeAllItem() {
  int j=0; 
  for (vector<Item*>::iterator i = ItemList.begin(); i != ItemList.end(); ++i,j++) { 
      ItemList.erase(ItemList.begin()+j);
 }
}



