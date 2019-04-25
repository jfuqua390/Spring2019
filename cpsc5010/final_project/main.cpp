#include <iostream>
#include <string>
#include <fstream>
#include "catalog.h"
#include "account.h"
using namespace std;

bool is_empt(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

void manageCatalog(Catalog* books) {
  cout << "Welcome to the Manage Catalog Interface, please select an option below: " << endl;
  bool finished = false;
  while(!finished) {
    cout << "(1)Add a book" << endl;
    cout << "(2)Delete a book" << endl;
    cout << "(3)View all books" << endl;
    cout << "(4)Search Books" << endl;
    cout << "(5)Sort Books" << endl;
    cout << "(0)Return to Main Menu" << endl;
    int option;
    cin >> option;
    switch (option) {
      case 0: finished = true; cout <<"Returning to Main Menu..." << endl; break;
      case 1: books->addBook(); break;
      case 2: books->deleteBook(); break;
      case 3: books->output(); break;
      case 4: {
        string t;
        cin.ignore();
        cout << "Enter title to search by: ";
        getline(cin, t);
        books->searchBooksByTitle(t);
        break;
      }
      case 5: {
        books->sortBooksBySalePrice();
        break;
      }
    }
  }
}

void transactions(Catalog* books, Account* acct) {
  cout << "Record your sale by using the options below: " << endl;
  bool finished = false;
  while(!finished) {
    cout << "(1)Record a sale" << endl;
    cout << "(2)Order a book" << endl;
    cout << "(3)View Balance" << endl;
    cout << "(4)View Average Price of Books" << endl;
    cout << "(0)Return to Main Menu" << endl;
    int option;
    cin >> option;
    switch(option) {
      case 0: finished = true; cout << "Returning to Main Menu..." << endl; break;
      case 1:{
        string title;
        int opt;
        cin.ignore();
        cout << "Enter exact title of book to sale:" << endl;
        getline(cin,title);
        Book* bookToSell = books->searchBooksByTitle(title);
        if(bookToSell->getTitle() != "undefined") {
          cout << "Is this the book you wish to delete(1:yes, 2:no)?" << endl;
          cin >> opt;
          if(opt == 1) {
            books->deleteBookByTitle(title);
            double amt = bookToSell->getSalePrice();
            acct->deposit(amt);
            cout << "Sale Recorded, Balance and Catalog Updated...." << endl;
            break;
          } else if(opt == 2) {
            cout << "Returning to Transactions Menu..." << endl;
            break;
          }
        }
        break;
      }
      case 2: {
        Book* lastbook;
        books->addBook();
        double amt;
        //for some reason get segment fault when trying getLastBookAdded (workaround for now)
        cout << "Enter cost of book: ";
        cin >> amt;
        acct->withdraw(amt);
        cout << "Purchase Recorded, Balance and Catalog Updated..." << endl;
        break;
      }
      case 3: acct->output(); break;
      case 4: cout << "Average Sales Price of Books: " << books->getAveragePriceOfBooks() << endl << endl; break;
    }
  }
}

int main() {
  int o;
  Catalog* books;
  Account* account;
  cout << "Welcome to Jonathan's Bookstore! Please use the following options to continue..." << endl;

  ifstream catFile("cat.txt");
  ifstream actFile("act.txt");

  if(is_empt(catFile) && is_empt(actFile)){
    cout << "I see that it is your first time here, please select how to import your catalog: " << endl;
    cout << "(1) Import catalog from text file" << endl;
    cout << "(2) Input catalog by hand" << endl;
    cin >> o;
    if(o==1) {
      string fname;
      cout << "Enter the exact file name you would like to upload (.txt files only): ";
      cin >> fname;
      books = new Catalog(fname);
    } else if(o==2) {
      books = new Catalog();
    } else {
      cout << "Command not recognized, aborting..." << endl;
      return 0;
    }
    double bal;
    cout << "Next we need to set up your account, please enter your account balance now: " << endl;
    cin >> bal;
    account = new Account(bal);
    cout << "Thank you for setting up your account!" << endl << endl;
  } else {
    cout << "Loading previously stored data..." << endl;
    books = new Catalog("cat.txt");
    double b = 0;
    double x = 0;
    fstream nFile;
    nFile.open("act.txt");
    while(nFile >> x) {
      b = x;
    }
    nFile.close();
    account = new Account(b);
  }

  bool finished = false;
  while(!finished) {
    cout << "Please select an option: (1)Manage Catalog; (2)Transactions; (0)Exit" << endl;
    int option;
    cin >> option;
    switch (option) {
      case 0: {
        books->writeToFile();
        account->writeToFile();
        finished = true;
        break;
      }
      case 1: manageCatalog(books); break;
      case 2: transactions(books, account); break;
    }
  }
  return 0;
}
