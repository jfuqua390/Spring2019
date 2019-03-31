// Lesson22_MIS_Department.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
using namespace std;

//date class
class Date {
private:
    int year, month, day;
public:
    Date(int year, int month, int day) {
        this->year = year; this->month = month; this->day = day;
    }
    void output() { cout << year << "/" << month << "/" <<day << endl; }
};

//Student class
class Student {
private:
public:
  string name;
  Date *birthday;
  double gpa;
    Student() {
      //For future, never use a constructor that has cin very poor design
        cout << "Enter name:"; cin >> name;

        cout << "Enter birth year, month, and day:";
        int year, month, day;
        cin >> year >> month >> day;
        birthday = new Date(year, month, day);

        cout << "Enter GPA"; cin >> gpa;
    } // default constructor

    ~Student() { delete[] birthday; }

    void output() {
        cout << "Name: " << name << " GPA: " << gpa << " Birthday: ";
        birthday->output();
    } // output everything about student
};

struct student_node {
  Student student_data;
  student_node* next;
  student_node* Next() {return next;};
  Student Data() {return student_data;};
  void SetNext(student_node* aNext) {next = aNext;};
};

class linked_list {
  student_node *head;
  student_node *last;

public:
  void append() {
    student_node *new_node = new student_node;
      // new_node->student_data = *new_student;
      new_node->next = NULL;

      if (head == NULL) {
          head = new_node;
          last = new_node;
      } else {
          last->next = new_node;
          last = new_node;
      }
  }

  void print() {
    student_node *tmp = head;

    //no Nodes
    if(tmp == NULL) {
      cout << "Nothing to display" << endl;
      return;
    }

    //One node
    if(tmp->Next() == NULL) {
      tmp->Data().output();
      // cout << tmp->Data().name << endl;
    } else {
      do {
        tmp->Data().output();
        // cout << tmp->Data().name << endl;
        cout << "----------" << endl;
        tmp = tmp->Next();
      }
      while(tmp != NULL);
    }
  }

  void delete_student(string student_name) {
    student_node *tmp = head;

    if(tmp == NULL) {
      cout << "No students to remove." << endl;
      return;
    }

    if(tmp->Next() == NULL) {
      delete tmp;
      head = NULL;
    } else {
      student_node *prev;
      do {
        if(tmp->Data().name == student_name) break;
        prev = tmp;
        tmp = tmp->Next();
      } while (tmp != NULL);

      //Adjust pointers
      prev->SetNext(tmp->Next());

      delete tmp;
    }
  }
};

class Department {
private:
    const int MaxStudentNum = 100;
    int numberStudents;
    linked_list list;
public:
    Department() {
        cout << "Enter the number of students:"; cin >> numberStudents;
        for (int i=0; i<numberStudents; i++) {
          list.append();
        }
    } // default constructor

    ~Department() {
        // for (int i = 0; i < numberStudents; i++) delete[] list[i];
        // delete[] list;
    } // destructor

    void output() {
      list.print();
    }  // output()

    //Adds a student to the dept
    void addStudent() {
        numberStudents ++;
        list.append();
    }

    //Deletes a student from the dept
    void deleteStudent() {
      string name;
      cout << "Enter student name to delete: "; cin >> name;
      list.delete_student(name);
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
