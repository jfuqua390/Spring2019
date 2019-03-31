// Lesson22_MIS_Department.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
using namespace std;

//Date class
class Date {
private:
    int year, month, day;
public:
    Date(int year, int month, int day) {
        this->year = year; this->month = month; this->day = day;
    }
    void output() { cout << year << month << day << endl; }
};

//Student class
class Student {
private:
  string name;
  Date *birthday;
  double gpa;
public:
  Student() {
    cout << "Enter name:"; cin >> name;

    cout << "Enter birth year, month, and day:";
    int year, month, day;
    cin >> year >> month >> day;
    birthday = new Date(year, month, day);

    cout << "Enter GPA"; cin >> gpa;
  } // default constructor

  ~Student() { delete[] birthday; }

  void output() {
    cout << name << gpa << endl;
    birthday->output();
  } // output everything about student
};


// Node class
class Node {
    Student data;
    Node* next;

  public:
    Node() {};
    void SetData(Student aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    Student Data() { return data; };
    Node* Next() { return next; };
};




// List class
class List {
    Node *head;
  public:
    List() { head = NULL; };
    void Print();
    void Append(Student data);
    void Delete(int data);
};

/**
 * Print the contents of the list
 */
// void List::Print() {
//
//     // Temp pointer
//     Node *tmp = head;
//
//     // No nodes
//     if ( tmp == NULL ) {
//     cout << "EMPTY" << endl;
//     return;
//     }
//
//     // One node in the list
//     if ( tmp->Next() == NULL ) {
//     cout << tmp->Data();
//     cout << " --> ";
//     cout << "NULL" << endl;
//     }
//     else {
//     // Parse and print the list
//     do {
//         cout << tmp->Data();
//         cout << " --> ";
//         tmp = tmp->Next();
//     }
//     while ( tmp != NULL );
//
//     cout << "NULL" << endl;
//     }
// }

/**
 * Append a node to the linked list
 */
void List::Append(Student data) {

    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->SetNext(newNode);
    }
    else {
    // First node in the list
    head = newNode;
    }
}

/**
 * Delete a node from the list
 */
// void List::Delete(int data) {
//
//     // Create a temp pointer
//     Node *tmp = head;
//
//     // No nodes
//     if ( tmp == NULL )
//     return;
//
//     // Last node of the list
//     if ( tmp->Next() == NULL ) {
//     delete tmp;
//     head = NULL;
//     }
//     else {
//     // Parse thru the nodes
//     Node *prev;
//     do {
//         if ( tmp->Data() == data ) break;
//         prev = tmp;
//         tmp = tmp->Next();
//     } while ( tmp != NULL );
//
//     // Adjust the pointers
//     prev->SetNext(tmp->Next());
//
//     // Delete the current node
//     delete tmp;
//     }
// }

class Department {
private:
    const int MaxStudentNum = 100;
    int numberStudents;
    Student** list;
public:
    Department() {
        List list;

        cout << "Enter the number of students:"; cin >> numberStudents;
        for (int i=0; i<numberStudents; i++) list.Append(new Student());
    } // default constructor

    ~Department() {
        for (int i = 0; i < numberStudents; i++) delete[] list[i];
        delete[] list;
    } // destructor

    void output() {
        list.Print();
    }  // output()

    void addStudent() {
        if (numberStudents < MaxStudentNum) list[numberStudents++] = new Student();
    }
    void deleteStudent() {
        delete[] list[--numberStudents];
    }
    void store() {
        cout << "under construction" << endl;
    }

};

int main()
{
    // part 1: instantiate a class cps
    Department cps;

    // part2: manipulate the students info in cps
    bool finished = false;
    while (!finished) {
        cout << "select: (0)output; (1)add; (2)delete; (3)store; (4)exit" << endl;
        int option;
        cin >> option;
        switch (option) {
        case 0: cps.output(); break;
        case 1: cps.addStudent(); break;
        case 2: cps.deleteStudent(); break;
        case 3: cps.store(); break;
        case 4: finished = true; break;
        default: cout << "wrong option!" << endl;
        } // switch
    } // while

    return 0;
}
