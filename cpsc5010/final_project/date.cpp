#include <iostream>
#include "date.h"
using namespace std;

Date::Date() {
  cout << "Enter year, month, and day" << endl;
  cin >> year >> month >> day;
  // cin.sync();
  cin.ignore();
}

Date::Date(int year, int month, int day) {
    this->year = year; this->month = month; this->day = day;
}

void Date::output() {
  cout << year << "/" << month << "/" << day;
}

int Date::getYear() {
  return year;
}

int Date::getMonth() {
  return month;
}

int Date::getDay() {
  return day;
}
