#include <iostream>
#include <stdlib.h>     // library for rand & srand from 
#include <time.h>       // library for time
// libraries from http://www.cplusplus.com/reference/cstdlib/srand/

using namespace std;

int game(){
  /* declaring variables, r is  secret number, i is user guess, n is number of guesses. */
  int r,i,n=0;
  // set random seed using clock
  srand (time(NULL));
  // generate random number between 0-100 inclusive
  r = rand() % 101;

  //initial guess
  cout << "enter your guess between 0-100 ";
  cin >> i;
 
  while (i!=r) {
     //for every new guess whileloop repeats, n increases
     n=n+1;

     if (i<r){
       cout << "your guess was too small. \n"; }
     /*we are inside the while loop, so  i is either >r or >r, never =r. if/else will do the trick*/
     else {
       cout << "your guess was too big. \n"; }

     cout << " try again ";
     //new input, repeat whileloop
     cin >> i;
  }

  //if you guess the right number
  if (i==r) {
    cout << " CONGRATS you guessed the secret number " << i << "\n" ;
    cout << "number of guesses is " << n+1 <<"\n";
  }
  return 0;
}

int main(){
  int ans=1;

while (ans==1) {
  game();
  
  //prompt to restart game
  cout << " play again? type 0 for no, 1 for yes \n";
  cin >> ans;
  
  //if play again, does game function again
  if (ans==1){
    cout << " game restart \n";}
 } 
 return 0;
}



