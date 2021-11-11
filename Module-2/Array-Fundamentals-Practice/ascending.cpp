#include <cstdlib>
#include <iostream>

using namespace std;

/* Takes array, and array length
returns true if array is in ascending order otherwiser returns false */
bool isSorted(int array[], int numItems)
{
  bool sortFlag = true;
  for(int j = 1; j <  numItems; j++){ //starts at one as 0 element can't be out of order
    if (array[j] < array[j-1]){
      sortFlag = false;
    }
  }
  return sortFlag;
}


int main(int argc, char** argv) {
 
  const int TEST_ARRAY_1_SIZE = 7;
  int testArray1[TEST_ARRAY_1_SIZE] = {4, 2, 4, 5, 6, 7, 8};
  cout << "isSorted returned " << isSorted(testArray1, TEST_ARRAY_1_SIZE) << "\n";
  int testArray2[TEST_ARRAY_1_SIZE] = {1, 4, 6, 7, 9, 12, 25};
  cout << "isSorted returned " << isSorted(testArray2, TEST_ARRAY_1_SIZE) << "\n";
  int testArray3[TEST_ARRAY_1_SIZE] = {2, 2, 4, 5, 6, 7, 8};
  cout << "isSorted returned " << isSorted(testArray3, TEST_ARRAY_1_SIZE) << "\n";
  int testArray4[TEST_ARRAY_1_SIZE] = {1, 2, 4, 5, 6, 7, 6};
  cout << "isSorted returned " << isSorted(testArray4, TEST_ARRAY_1_SIZE) << "\n";
  
  //variaous inputs to test edge cases.

  return 0;
}
