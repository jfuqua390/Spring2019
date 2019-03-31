#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*
Suppose the weekly hours for all employees are stored in a two-dimensional array.
Each row records an employee’s seven-day work hours with seven columns.
Write a program that displays employees and their total hours in decreasing order of the total hours.
*/

void printEmployees(vector<vector<int>>& hours) {
  for(int i = 0; i < 5; i++) {
    cout << hours[i][0] << " -- " << hours[i][1] << endl;
  }
}

bool sort_column(const vector<int>& v1, const vector<int>& v2) {
  return v1[1] > v2[1];
}

int main() {
  int weekly_hours[5][7] = {
    {6,5,5,5,6,7,3},
    {8,9,7,8,6,5,5},
    {5,4,3,3,2,2,2},
    {6,5,4,6,5,5,9},
    {5,4,4,4,3,4,3}
  };

  vector< vector<int> > employee_hours_worked{
    {1,0},
    {2,0},
    {3,0},
    {4,0},
    {5,0},
  };

  int rows = employee_hours_worked.size();
  int col = employee_hours_worked[0].size();

  for (int i = 0; i < 5; i++) {
    int sum = 0;
    for(int j = 0; j < 7; j++) {
      sum += weekly_hours[i][j];
    }
    employee_hours_worked[i][1] = sum;
  }

  cout << "Before Sorting: " << endl;
  printEmployees(employee_hours_worked);

  sort(employee_hours_worked.begin(), employee_hours_worked.end(), sort_column);

  cout << "After Sorting:" << endl;
  printEmployees(employee_hours_worked);
}
