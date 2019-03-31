#include <iostream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  double weight;
  int int_letter;
  double post;
  //Prompt user inputs
  cout << "Enter weight of letter(in grams): ";
  cin >> weight;
  cout << "Is this international letter (0=no, 1=yes): ";
  cin >> int_letter;

  //if the weight is less than or equal to 30 and not an international letter
  if(weight <= 30 && int_letter == 0) {
    post = .41;
  } //if weight is greater than 30 and not an international letter
  else if(weight > 30 && int_letter == 0) {
    post = .41 + .05 * (weight - 30);
  } //if weight is less than 30 but is an international letter
  else if(weight <= 30 && int_letter == 1) {
    post = .41 + .41*.15;
  } //if weight is greater than 30 and is an international letter
  else if(weight > 30 && int_letter == 1) {
    post = (.41 + .05 * (weight - 30)) + (.41 + .05 * (weight - 30)) * .15;
  }
  //print and return the post
  cout << "post is: " << post << endl;
  return post;

} // end of main()
