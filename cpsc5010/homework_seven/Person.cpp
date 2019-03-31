#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

/* Design a class named Person and its two subclasses named Student and Employee.
Make Faculty and Staff subclasses of Employee.
A person has a name, address, phone number, and email address.
A student has a class status (freshman, sophomore, junior, or senior). Define the status as a constant.
An employee has an office, salary, and date hired. Use the MyDate classto create an object for date hired.
A faculty member has office hours and a rank. A staff member has a title.
Override the output() method in each class to display the class name and the person’s name.
*/

class Date {
private:
  int year, month, day;
public:
  Date(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
  }
  void output() {
    cout << year << "/" << month << "/" << day;
  }
  int getYear() {
    return year;
  }
  int getMonth() {
    return month;
  }
  int getDay() {
    return day;
  }
};

class Person {
public:
  //data fields
  string name, address, phone, email;

  Person(string _name, string _address, string _phone, string _email) {
    name = _name;
    address = _address;
    phone = _phone;
    email = _email;
  }

  //output to display what needed
  void output() {
    cout << "Class: Person, Name: " << name << endl;
  }
};

//Student is subclass of person
class Student : public Person {
private:
  //set private and provide no set method so it is constant
  string status;
public:

  Student(string _name, string _address, string _phone, string _email, string _status)
    : Person(_name,_address,_phone,_email) {
    status = _status;
  }

  //output to display what needed
  void output() {
    cout << "Class: Student, Name: " << name << endl;
  }
};

class Employee : public Person {
public:
  //the MyDate class is a java class C++ doesn't have these as far as I know... so made new one?
  string office;
  Date *date_hired;
  double salary;

  Employee(string _name, string _address, string _phone, string _email, string _office, int year_hired, int month_hired, int day_hired, double _salary) :
    Person(_name, _address, _phone, _email) {
      office = _office;
      date_hired = new Date(year_hired, month_hired, day_hired);
      salary = _salary;
    }

  void output() {
    cout << "Class: Employee, Name: " << name << endl;
  }
};

class Faculty : public Employee {
public:
  string office_hours, rank;

  Faculty(string _name, string _address, string _phone, string _email, string _office, int year_hired, int month_hired, int day_hired, double _salary, string _office_hours, string _rank) :
      Employee(_name, _address, _phone, _email, _office, year_hired, month_hired, day_hired, _salary)  {
        office_hours = _office_hours;
        rank = _rank;
      }

  void output() {
    cout << "Class: Faculty, Name: " << name << endl;
  }
};

class Staff : public Employee {
public:
  string title;

  Staff(string _name, string _address, string _phone, string _email, string _office, int year_hired, int month_hired, int day_hired, double _salary, string _title) :
      Employee(_name, _address, _phone, _email, _office, year_hired, month_hired, day_hired, _salary)  {
        title = _title;
      }

      void output() {
        cout << "Class: Staff, Name: " << name << endl;
      }
};

int main() {
  Person steve("Steve", "123 Absolut Ln", "865-634-4343", "steve@gmail.com");
  steve.output();
  Student adam("Adam", "145 Adam Dr", "655-505-3245", "adam@gmail.com", "Freshman");
  adam.output();
  Employee bob("Bob", "456 Bob Dr.", "555-442-3453", "bob@gmail.com", "415B",2009,2,12, 35000.00);
  bob.output();
  Faculty erin("Erin", "433 Erin Dr", "454-343-4444", "erin@gmail.com", "330C", 2010,4,29,40000.00, "T-TH 3:00 - 5:00", "Graduate Rank");
  erin.output();
  Staff kelly("Kelly", "433 Kelly Dr", "454-343-4233", "kelly@gmail.com", "330B", 2011, 2, 15, 20000.00, "Janitor");
  kelly.output();

  return 0;
}
