#include "catalog.h"
#include <fstream>

Catalog::Catalog() { // default constructor
    list = new Book*[MaxBookNum];

    cout << "Enter the number of books:"; cin >> numberOfBooks;
    cin.ignore();
    cout << "Generating catalog..." << endl;
    cout << "Enter information of each book as instructed..." << endl;
    for (int i=0; i<numberOfBooks; i++) {
      cout << "Book " << i+1 << " Information..." << endl;
      list[i] = new Book();
      cin.ignore();
    }
}

//read from file
Catalog::Catalog(string filename) {
  list = new Book*[MaxBookNum];
  string line;
  string item;
  int i = 0;
  ifstream myfile (filename);
  if(myfile.is_open()){
    while(getline(myfile,line)) {
      list[i] = new Book(line);
      i++;
    }
    myfile.close();
  } else {
    cout << "unable to open file..." << endl;
  }
  numberOfBooks += i;
}

Catalog::~Catalog() {
    for (int i = 0; i < numberOfBooks; i++) delete[] list[i];
    delete[] list;
} // destructor

void Catalog::output() {
    for (int i = 0; i < numberOfBooks; i++) list[i]->output();

    cout << "Total Books: " << numberOfBooks << endl;
    cout << endl;
}

void Catalog::addBook() {
    if (numberOfBooks < MaxBookNum) {
      list[numberOfBooks++] = new Book();
    } else {
      cout << "Too many books!" << endl;
    }
}

void Catalog::deleteBook() {
    for (int i = 0; i < numberOfBooks; i++) {
      cout << "ID: " << i << "; ";
      list[i]->output();
    }
    int idToDelete;
    cout << "Enter Id of Book to Delete: ";
    cin >> idToDelete;
    for(int j = idToDelete; j < numberOfBooks; j++) {
      list[j] = list[j+1];
    }
    numberOfBooks--;
}


Book* Catalog::searchBooksByTitle(string t) {\
  for(int i = 0; i < numberOfBooks; i++) {
    if(list[i]->getTitle() == t) {
      cout << "Book found!" << endl;
      list[i]->output();
      cout << endl;
      return list[i];
    }
  }
  cout << "Book not found." << endl;
  cout << endl;
  return new Book("undefined;undefined;undefined;undefined;undefined;undefined;undefined;undefined");
}

Book* Catalog::getLastBookAdded() {
  return list[numberOfBooks];
}


void Catalog::deleteBookByTitle(string t) {
  int idToDelete;
  for(int i = 0; i < numberOfBooks; i++) {
    if(list[i]->getTitle() == t) {
      idToDelete = i;
    }
  }

  for(int j = idToDelete; j < numberOfBooks; j++) {
    list[j] = list[j+1];
  }
  numberOfBooks--;
}

void Catalog::sortBooksBySalePrice() {
  Book* temp;
  for(int i = 0; i < numberOfBooks; i++) {
    for(int j = i+1; j < numberOfBooks; j++) {
      if(list[i]->getSalePrice() > list[j]->getSalePrice()) {
          temp = list[i];
          list[i] = list[j];
          list[j] = temp;
      }
    }
  }
}

double Catalog::getAveragePriceOfBooks() {
  double sum = 0;
  for(int i = 0; i < numberOfBooks; i++) {
    sum += list[i]->getSalePrice();
  }
  return sum / numberOfBooks;
}

void Catalog::writeToFile() {
  ofstream myfile;
  myfile.open("cat.txt");
  for(int i = 0; i < numberOfBooks; i++) {
    myfile << list[i]->outputForText() + "\n";
  }
  myfile.close();
}
