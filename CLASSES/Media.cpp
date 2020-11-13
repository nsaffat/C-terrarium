#include "Media.h"
using namespace std;
//constructor, sets variables
Media::Media() {
  title = new char();
  checked = false;
}
//getter functions
char* Media::getTitle() {
	return title;
}

int Media::getYear() {
  return year;
}

void Media::printInfo() {}


