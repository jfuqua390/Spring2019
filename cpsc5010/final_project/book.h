#include <iostream>
#include <string>
#include "date.h"
using namespace std;

//Book class
class Book {
private:
  string title, author;
  int numberOfPages;
  double cost;
  double salePrice;
  Date* datePublished;
public:
  Book(); //Default constructor
  Book(string title, string author, int numberOfPages, Date* datePublished, double cost, double salePrice); //Parameterized Constructor
  Book(string k); //Constructor for adding from text file
  string getTitle(); //Returns title of book
  string getAuthor(); //returns author
  int getNumberOfPages(); //returns number of pages
  double getCost(); //returns cost
  double getSalePrice(); //returns sales price
  void output(); //couts info about the book
  string outputForText();
};
