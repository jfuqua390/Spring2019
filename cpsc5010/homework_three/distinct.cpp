#include <iostream>
#include <string>
using namespace std;

/*
Write a program that reads in ten numbers and displays distinct numbers
(i.e., if a number appears multiple times, it is displayed only once).
(Hint: Read a number and store it to an array if it is new.
If the number is already in the array, ignore it.) After the input, the array contains the distinct numbers.
*/

int main() {
  int num[10];
  int new_num[100000] = {0};
  int key;
  int flag = 0;

  for(int i = 0; i<10; i++) {
    cout << "Enter a number : ";
    cin >> num[i];
  }

  for(int j = 0; j < 10; j++) {
    key = num[j];
    for(int k = 0; k < 10; k++) {
      if(num[k] == key) {
        flag += 1;
      }
    }
    if(flag == 1) {
      cout << num[j] << " ";
    } else if(flag > 1) {
      new_num[num[j]] ++;
      if(new_num[num[j]] == 1) {
        cout << num[j] << " ";
      }
    }
    flag = 0;
  }
  cout << endl;
}
