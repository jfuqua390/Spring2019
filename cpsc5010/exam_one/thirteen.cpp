#include <iostream>
#include <string>
using namespace std;
#define sizeArray 100

int main() {
  //new dynamic array
  int* nums = new int[sizeArray];

  //declare variables
  int countEvens = 0;
  int countTotal = 0;
  int countArray = 0;
  int sum = 0;
  bool finished = false;

  //while loop to do user input
  while(!finished) {
    int x;
    cout << "Enter positive integers (negative or zero to end): " << endl;
    cin >> x;

    if(x > 0) {
      //positive number logic here
      countTotal++;

      //even number logic
      if(x % 2 == 0) {
        countEvens++;
      }
      //between 100 and 200 (non-inclusive)
      if(x > 100 && x < 200) {
        if(countArray < 100) {
          nums[countArray] = x;
        } else {
          cout << "Array is full. Number will count for evens but not for the average of numbers between 100 and 200." << endl;
        }
        countArray++;
      }
    } else {
      //end while loop if negative or zero entered
      finished = true;
    }
  }
  //Total evens
  cout << "Total Even Numbers: " << countEvens << endl;
  //Percentage of evens
  cout << "Percentage of evens: " << 100 * countEvens / countTotal << "%" << endl;
  //sum Array
  for(int i = 0; i < countArray; i++) {
    sum += nums[i];
  }
  //output average taking care of dividing by zero
  double avg = countArray > 0 ? 1.0 * sum / countArray : 0.0;
  cout << "Average of numbers between 100 and 200: " << avg << endl;
  delete[] nums;
  return 0;
}
