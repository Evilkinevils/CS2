#include <iostream>
#include <string>

using namespace std;

// Structure represeting a course
struct domino {
  int side1;
  int side2;
};

void printDomino(domino toPrint){
  int a = toPrint.side1;
  int b = toPrint.side2;
  cout << "_______________________\n"; 
  cout << "|          |          |\n";
  cout << "|  ";if(a==2||a==3||a==4||a==5||a==6){cout<<"*";}else{cout<<" ";}cout<<"    ";if(a==4||a==5||a==6){cout<<"*";}else{cout<<" ";}cout<<"  |  ";if(b==2||b==3||b==4||b==5||b==6){cout<<"*";}else{cout<<" ";}cout<<"    ";if(b==4||b==5||b==6){cout<<"*";}else{cout<<" ";}cout<<"  |\n";
  cout << "|  ";if(a==6){cout<<"*";}else{cout<<" ";}cout<<" ";if(a==3||a==5||a==1){cout<<"*";}else{cout<<" ";}cout<<"  ";if(a==6){cout<<"*";}else{cout<<" ";}cout<<"  |  ";if(b==6){cout<<"*";}else{cout<<" ";}cout<<" ";if(b==3||b==5||b==1){cout<<"*";}else{cout<<" ";}cout<<"  ";if(b==6){cout<<"*";}else{cout<<" ";}cout<<"  |\n";
  cout << "|  ";if(a==4||a==5||a==6){cout<<"*";}else{cout<<" ";}cout<<"    ";if(a==2||a==3||a==4||a==5||a==6){cout<<"*";}else{cout<<" ";}cout<<"  |  ";if(b==4||b==5||b==6){cout<<"*";}else{cout<<" ";}cout<<"    ";if(b==2||b==3||b==4||b==5||b==6){cout<<"*";}else{cout<<" ";}cout<<"  |\n";
  cout << "|          |          |\n";
  cout << "_______________________\n";
};

int main(){
  const int numOfDominoes = 28;
  domino deck[numOfDominoes];
  
  int placeKeeper = 0;
  for (int j = 0; j < 7; j++){
    for (int k = 0; k <= j; k++){
      deck[placeKeeper].side1 = j;
      deck[placeKeeper].side2 = k;
      placeKeeper++;
    }
  }

  int start = 0;
  int end = numOfDominoes - 1;
  for (int i = start + 1; i <= end; i++) {
    for (int j = i; j > start && deck[j-1].side2 > deck[j].side2; j--) { 
      domino temp = deck[j-1];
      deck[j-1] = deck[j];
      deck[j] = temp;
    }
  }

  for (int j = 0; j < numOfDominoes; j++){
    cout << "Current Domino " << deck[j].side1 << ", " << deck[j].side2 << " \n";

    printDomino(deck[j]);
    cout <<"\n\n";
  }

  return(0);
}
