#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
Write a program that generates 100 random integers between 0 and 9 and displays the count for each number.
(Hint: Use (int)(Math.random() * 10)to generatea random integer between 0 and 9.
Useanarrayoftenintegers, say counts, to store the counts for the number of 0s, 1s, ..., 9s.)

*/

int main() {
  int i = 0;
  int counts[10] = {0,0,0,0,0,0,0,0,0,0};
  srand((unsigned) time (NULL));

  while(i < 100) {
    int n = rand()%10;
    counts[n] ++;
    i++;
  }

  cout << "Counts: " << endl;
  for(int k = 0; k < 10; k++) {
    cout << k << "s:" << counts[k] << endl;
  }

}
