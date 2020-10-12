#include <iostream>
#include <cstring>
#include <locale>
// library from http://www.cplusplus.com/reference/locale/tolower/
using namespace std;

int main() {
  // declaring variables
  char input[80], final[80];
  int i=0,s=0,l=0;

  //filling the strings with 0s as placeholders
  for (i=0; i<80; i++) {
    input[i]=0;
    final[i]=0;
      }

  cout<< "enter phrase below. (dont use apostrophes) \n";
  //used cin.get so spaces would get read as characters
  cin.get (input, 80);

  //copying letters (no spaces or ,.?!;:") into nospace string
  for (i=0; i<80; i++) {
    if ((input[i] != ' ')&&(input[i] !=',')&&(input[i] !='.')&&(input[i] !='!')&&(input[i] !='?')&&(input[i] !=';')&&(input[i] !=':')&&(input[i] !='"')) {
      
      final[s] = input[i];
      s = s+1; }
  }

  cout << " str no spaces--> " << final << endl;

  //turn uppercases into lower and put into final string
  for (i=0; i<80; i++) {
    if (isupper(final[i])){
      final[i]= (tolower(final[i])); }
     }

  cout << " str no uppercase--> " << final << endl;
  l= strlen(final) - 1;

  //checks every char in string with the opposite one
  for(i=0; i<=l; i++){
    if (final[i]!= final[l-i]){
      cout << " is NOT a palindrome! ";
      break;}
    if (i == l) {
      cout << " is a palindrome! ";  }
  }

  return 0;
}
