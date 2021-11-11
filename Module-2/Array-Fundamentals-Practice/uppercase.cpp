#include <cstdlib>
#include <iostream>

using namespace std;

/* Takes array of characters, and array length
returns the number of upper case letters in the array */
int upperCount(char array[], int numItems)
{
  int count = 0;
  for(int j = 0; j <  numItems; j++){ 
    if (array[j] < 91 && array[j] > 64){
      count++;
    }
  }
  return count;
}

int main(int argc, char** argv) {
 
  const int TEST_ARRAY_1_SIZE = 10;
  char testArray1[TEST_ARRAY_1_SIZE] = { 'a', 't', 'j', 'R', 'G', 'C', 'v', 'h', 'Y', 'u'};
  cout << "That array had " << upperCount(testArray1, TEST_ARRAY_1_SIZE) << " uppercase letters\n";

  return 0;
}
