#include <iostream>

using namespace std;

/* Fuction takes positive int as input, returns factorial of intput as int */
int factorial(int num)
{
  int output = num;
  num--;
  while (num > 0)
  {
    output = output * num;    
    num--;
  }
  return output;
}

int main()
{
  for(int i=0; i <= 11; i=i+1)
  {
    cout << factorial(i) << endl;
  }
  return 0;
}
