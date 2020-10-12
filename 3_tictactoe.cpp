#include <iostream>
 
using namespace std;

//declaring and initializing variables
char ttt[10] = {'0','1','2','3','4','5','6','7','8','9'};
char input;
int turn, i, Xwins=0, Owins=0, again=1;



//function to reprint board outline with placeholders
void board() {
  cout << endl << endl;
  cout << " "<< ttt[1]<<" | "<< ttt[2]<<" | "<<ttt[3]<<" " << endl;
  cout << "---|---|---" << endl;
  cout << " "<< ttt[4]<<" | "<< ttt[5]<<" | "<<ttt[6]<<" " << endl;
  cout << "---|---|---" << endl;
  cout << " "<< ttt[7]<<" | "<< ttt[8]<<" | "<<ttt[9]<<" " << endl;
  cout << endl;
}

//function for 1 round of input/gameplay
void gameplay () {

  //gameplay() is the same for X or O's turn. Odd numbered turn means X, even numbered turn means O
  if (turn % 2 == 1)  {
    cout << "Player X turn. ";}
  else {
    cout << "Player O turn. ";}

  //prompt to enter your next move
  cout << "Enter location of move " ;
  cin >> input;

  //for loop to check if player chose a valid location for their mark
  for (i=0; i<10; i++) {
    if (input == ttt[i]) {
      if (turn % 2 == 1)  {
	ttt[i] = 'X';}
      else {
	ttt[i] = 'O'; }
      turn = turn + 1;
      break;
    }
    if (i==9) {
      cout << "input invalid. try again";
    }
  }
}

//function to check if three in a row is present of the board
bool threeinarow() {
  if (ttt[1] == ttt[2] && ttt[2] == ttt[3]) {
    return true;}
  if (ttt[4] == ttt[5] && ttt[5] == ttt[6]) {
    return true;}
  if (ttt[7] == ttt[8] && ttt[8] == ttt[9]) {
    return true;}
  
  if (ttt[1] == ttt[4] && ttt[4] == ttt[7]) {
    return true;}
  if (ttt[2] == ttt[5] && ttt[5] == ttt[8]) {
    return true;}
  if (ttt[3] == ttt[6] && ttt[6] == ttt[9]) {
    return true;}

  if (ttt[1] == ttt[5] && ttt[5] == ttt[9]) {
    return true;}  
  if (ttt[3] == ttt[5] && ttt[5] == ttt[7]) {
    return true;}
  
  else {
    return false;}
  }


int main() {

while (again==1) {
  
  board ();
  turn = 1;

  //when three in a row happens, while loop breaks. turn = 10 means that no winner declared but board is filled up so must be a tie
  while (turn <= 10) {
    gameplay ();
    board ();
    threeinarow ();
    if (threeinarow() == true) {
      if (turn % 2 == 1)  {
	cout << "winner is Player O \n";
	Owins = Owins + 1;
      }
      else {
	cout << "winner is Player X \n";
	Xwins = Xwins + 1;
      }
      cout << " Player X has " << Xwins << " wins & Player O has " << Owins << " wins \n ";
      break;}
      
    if (turn == 10) {
      cout << " game is a TIE ";
      break; }
  }
  
  //prompt to restart game
  cout << endl <<  "Play again? type 0 for no, 1 for yes ";
  cin >> again;

  //if user wants to play again, the board is reset
  if (again==1){
    ttt[1]= '1';
    ttt[2]= '2';
    ttt[3]= '3';
    ttt[4]= '4';
    ttt[5]= '5';
    ttt[6]= '6';
    ttt[7]= '7';
    ttt[8]= '8';
    ttt[9]= '9';
  }
 }
  return 0;

}






