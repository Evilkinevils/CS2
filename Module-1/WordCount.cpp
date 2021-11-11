#include <cstdlib>
#include <iostream>

using namespace std;

/* Count variables */
char digit;
int letterCount = 0;
int NLPCount = 0;
int vowelCount = 0;
bool previousWasLetter;
  
int wordCount = 0;
int longestWord = 0;
int longestWordNLP = 0;
int mostVowels = 0;

/* Takes Char as input, returns true if char is a capital or lowercase letter */
bool isLetter(char x){
  return((x < 123 && x > 96) || (x > 64 && x < 91));
}

/* Takes Char as input, return true if char is a vowel */
bool isVowel(char x){
  bool isLowerVowel = (x == 97 || x == 101 || x == 105 ||  x == 111 || x == 117);
  bool isUpperVowel = (x == 65 || x == 69 || x == 73 ||  x == 79 || x == 85);
  return(isLowerVowel || isUpperVowel);
}

/* Takes Char as input, returns true if char a Hyphen or an Apostrophy */
bool isNLP(char x){
  return(x == 45 || x == 39);
}

/* Resets single word counters */
void countReset(){
  letterCount = 0;
  NLPCount = 0;
  vowelCount = 0;
  previousWasLetter = false;
}

/* Resets all counters */
void fullReset(){
  letterCount = 0;
  NLPCount = 0;
  vowelCount = 0;
  previousWasLetter = false;
  wordCount = 0;
  longestWord = 0;
  longestWordNLP = 0;
  mostVowels = 0;
}

/* Takes an int and returns an 's ' if true or ' ' if not */
string isPlural(int x){
  if(x != 1){
    return("s ");
  }
  else{
    return(" ");
  }
}


int main(int argc, char** argv) {
  while(true){
    cout << "Enter a string of words: ";

    while(digit != 10){
      digit = cin.get();

    /* debugging string */
    /* cout << digit << ", " << letterCount <<  ", " << isVowel(digit) << '\n'; */

      if (isLetter(digit))
      {
        letterCount = letterCount + 1;
        previousWasLetter = true;
        if(isVowel(digit)){
          vowelCount = vowelCount +1;
        }
      }
      else if(isNLP(digit) && previousWasLetter)
      {
        letterCount = letterCount + 1;
        NLPCount = NLPCount + 1;
        previousWasLetter = false;
      }
      else if(letterCount > 0)
      {
        wordCount = wordCount + 1;
        if(letterCount > (longestWord - longestWordNLP))
        {
          longestWord = letterCount;
          longestWordNLP = NLPCount;
        }
        if(vowelCount > mostVowels)
        {
          mostVowels = vowelCount;
        }
        countReset();
      }
    }

    if(wordCount == 0){
      cout << "No words were entered\n\n";
    }
    else if(wordCount == 1 && longestWordNLP > 0){
      cout << "There was only one word.\n";
      cout << "It was " << (longestWord-longestWordNLP) << " letter" << isPlural(longestWord) <<"long, " << longestWord << " if you include punctuation.\n";
      cout << "It had " << mostVowels << " vowel" << isPlural(mostVowels) <<"in it.\n\n";
    }
    else if(wordCount == 1){
      cout << "There was only one word.\n";
      cout << "It was " << longestWord << " letter" << isPlural(longestWord) <<"long.\n";
      cout << "It had " << mostVowels << " vowel" << isPlural(mostVowels) <<"in it.\n\n";
    }
    else if(longestWordNLP > 0){
      cout << "There were " << wordCount << " words.\n";
      cout << "The longest one was " << (longestWord-longestWordNLP) << " letter" << isPlural(longestWord-longestWordNLP) <<"long, " << longestWord << " if you include punctuation.\n";
      cout << "The most vowels in a single word was " << mostVowels << ".\n\n";
    }
    else{
      cout << "There were " << wordCount << " words.\n";
      cout << "The longest one was " << longestWord << " letter" << isPlural(longestWord) <<"long.\n";
      cout << "The most vowels in a single word was " << mostVowels << ".\n\n";
    }
    fullReset();
    digit = 0;
  }
  return 0;
}
