#ifndef ROOM_H
#define ROOM_H
#include <vector>
using namespace std;

struct Item {char name[10]; int room;};

class Room {
 private:
  int RoomID; 
  Room *NorthExit, *SouthExit, *WestExit, *EastExit;
  vector<Item*> ItemList;
  
 public:
  Room();
  ~Room();
  
  int getRoomID();
  Room* getNorthExit();
  Room* getSouthExit();
  Room* getWestExit();
  Room* getEastExit();
  vector<Item*> getItemList();

  void setRoomID(int);
  void setNorthExit(Room*);
  void setSouthExit(Room*);
  void setWestExit(Room*);
  void setEastExit(Room*);
  void addItem(Item*);
  void removeItem(const char*);
  void removeAllItem();
  void printItems();
  void printExits();
  
};
#endif
