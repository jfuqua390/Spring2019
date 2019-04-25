#include "book.h"
#include <iostream>
#include <string>
using namespace std;

class Catalog {
private:
    //can't use malloc or vectors so need to do this way for now.
    const int MaxBookNum = 100;
    int numberOfBooks = 0;
    Book** list;
public:
  Catalog();
  Catalog(string filename); //read inputs from txt file
  ~Catalog();
  void output(); //View all Books
  void addBook(); //Add Book
  void deleteBook(); //Delete book
  Book* searchBooksByTitle(string title); //Search Books by Title
  void deleteBookByTitle(string t); //Delete a book by title
  Book* getLastBookAdded(); //Get last book added (used in order to deduct the cost from balance when recording a purchase)
  void sortBooksBySalePrice(); //Just a sort function to show that I can sort arrays
  double getAveragePriceOfBooks(); //Just a function to get avg sales price of all books
  void writeToFile(); //save data to txt file
};
