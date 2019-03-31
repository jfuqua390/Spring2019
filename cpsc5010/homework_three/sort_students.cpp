#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
Write a program that prompts the user to enter the number of students, the students’ names,
and their scores, and prints student names in decreasing order of their scores.
*/

struct Student {
  string name;
  int score;
};
bool sortByScoreDesc(const Student &lhs, const Student &rhs) {return lhs.score > rhs.score;}

int main() {
  int size = 0;
  cout << "Enter number of students: ";
  cin >> size;


  vector<Student> list(size);

  for(int i = 0; i < size; i++) {
    cout << "Enter student name: " << endl;
    cin >> list[i].name;
    cout << "Enter student score: " << endl;
    cin >> list[i].score;
  }
  //using std:sort because it's easiest
  sort(list.begin(), list.end(), sortByScoreDesc);
  for(int k = 0; k < size; k++) {
    cout << list[k].name << " - " << list[k].score << endl;
  }
}
