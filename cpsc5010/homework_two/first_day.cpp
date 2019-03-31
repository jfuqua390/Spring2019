#include <iostream>
#include <string>
using namespace std;

/*
Write a program that prompts the user to enter the year and first day of the year, and displays the first day of each month in the year on the console.
For example, if the user entered the year 2013, and 2 for Tuesday, January 1, 2013, your program should display the following output:

         January 1, 2013 is Tuesday
         ...
         December 1, 2013 is Sunday
*/

int main() {
  int year, day;
  cout << "Enter the year and day(1 for Monday, 2 Tuesday, etc.)" << endl;
  cin >> year >> day;
  int days_in_month = 0;
  string day_word;

  for (int month = 1; month <= 12; month++) {
    switch(month) {
      case 1:
        cout << "January 1, " << year << " is ";
        days_in_month = 31;
        break;
      case 2:
        cout << "February 1, " << year << " is ";
        if((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0)) {
          days_in_month = 29;
        } else {
          days_in_month = 28;
        }
        break;
      case 3:
        cout << "March 1, " << year << " is ";
        days_in_month = 31;
        break;
      case 4:
        cout << "April 1, " << year << " is ";
        days_in_month = 30;
        break;
      case 5:
        cout << "May 1, " << year << " is ";
        days_in_month = 31;
        break;
      case 6:
        cout << "June 1, " << year << " is ";
        days_in_month = 30;
        break;
      case 7:
        cout << "July 1, " << year << " is ";
        days_in_month = 31;
        break;
      case 8:
        cout << "August 1, " << year << " is ";
        days_in_month = 31;
        break;
      case 9:
        cout << "September 1, " << year << " is ";
        days_in_month = 30;
        break;
      case 10:
        cout << "October 1, " << year << " is ";
        days_in_month = 31;
        break;
      case 11:
        cout << "November 1, " << year << " is ";
        days_in_month = 30;
        break;
      case 12:
        cout << "December 1, " << year << " is ";
        days_in_month = 31;
        break;
    }
    switch(day) {
      case 0:
        day_word = "Sunday";
        break;
      case 1:
        day_word = "Monday";
        break;
      case 2:
        day_word = "Tuesday";
        break;
      case 3:
        day_word = "Wednesday";
        break;
      case 4:
        day_word = "Thursday";
        break;
      case 5:
        day_word = "Friday";
        break;
      case 6:
        day_word = "Saturday";
        break;
    }

    cout << day_word << endl;
    day = (day + days_in_month) % 7;
  }
}
