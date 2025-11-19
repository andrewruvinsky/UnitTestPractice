#include "Password.h"
#include <string>
#include <vector>

using std::string;
using namespace std;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if (phrase.length() == 0){
    return 0;
  }

  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/* Receives a string and returns a count of how many case-sensitive
unique characters there are. If there are duplicate instances of
the same character it should only count as a single character.
Even if characters look similar, as long as they have distinct ASCII values,
they should qualify as unique characters. */

unsigned int Password::unique_characters(string str) {
  vector<char> unique_chars;

  for (char c : str) {
    bool found = false;

    for (char u : unique_chars) {
      if (u == c) {
        // Character already counted, break out of inner loop
        found = true;
        break;
      }
    }

    if (!found) {
      unique_chars.push_back(c);
    }
  }

  return unique_chars.size();
}

/* receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter (Implementation E) */
bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}