#include "book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

Book::Book() { //Default Constructor
  cin.ignore();
  cout << "Enter title:" << endl;
  getline(cin,title);
  cout << "Enter author:" << endl;
  getline(cin,author);
  cout << "Enter number of pages:" << endl;
  cin >> numberOfPages;
  int y,m,d;
  cout << "Enter year, month, and day published:" << endl;
  cin >> y >> m >> d;
  datePublished = new Date(y,m,d);
  cout << "Enter cost and sale price:" << endl;
  cin >> cost >> salePrice;
}

Book::Book(string title, string author, int numberOfPages, Date* datePublished, double cost, double salePrice) { //Parameterized constructor
  this->title = title;
  this->author = author;
  this->numberOfPages = numberOfPages;
  this->datePublished = datePublished;
  this->cost = cost;
  this->salePrice = salePrice;
}

Book::Book(string k) { //creates a new book from a string
  vector<string> tokens;
  string token;
  size_t pos = 0;
  string delim = ";";
  int year, month, day;

  while((pos = k.find(delim)) != string::npos) {
    token = k.substr(0, pos);
    tokens.push_back(token);
    k.erase(0, pos + delim.length());
  }
  title = tokens[0];
  author = tokens[1];
  stringstream pages(tokens[2]);
  stringstream y(tokens[3]);
  stringstream m(tokens[4]);
  stringstream d(tokens[5]);
  stringstream c(tokens[6]);
  stringstream s(tokens[7]);

  pages >> numberOfPages;
  y >> year;
  m >> month;
  d >> day;
  datePublished = new Date(year, month, day);
  c >> cost;
  s >> salePrice;
}

string Book::getTitle() {
  return title;
}

string Book::getAuthor() {
  return author;
}

int Book::getNumberOfPages() {
  return numberOfPages;
}

double Book::getCost() {
  return cost;
}

double Book::getSalePrice() {
  return salePrice;
}

void Book::output() { //output book information
  cout << "Title: " << title << "; Author: " << author << "; NumPages: " << numberOfPages << "; Published: ";
  datePublished->output();
  cout << "; Cost: " << cost << "; Sale Price: " << salePrice << endl;
}

string Book::outputForText() {
  return title + ";" + author + ";" + to_string(numberOfPages) + ";" + to_string(datePublished->getYear()) + ";"
          + to_string(datePublished->getMonth()) + ";" + to_string(datePublished->getDay()) + ";" + to_string(cost) + ";"
          + to_string(salePrice) + ";";
}
