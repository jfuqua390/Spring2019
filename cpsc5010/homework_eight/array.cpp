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

class Department {
private:
    const int MaxStudentNum = 100;
    int numberStudents;
    Student** list;
public:
    Department() {
        list = new Student*[MaxStudentNum];

        cout << "Enter the number of students:"; cin >> numberStudents;
        for (int i=0; i<numberStudents; i++) list[i] = new Student();
    } // default constructor

    ~Department() {
        for (int i = 0; i < numberStudents; i++) delete[] list[i];
        delete[] list;
    } // destructor

    void output() {
        for (int i = 0; i < numberStudents; i++) list[i]->output();
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
