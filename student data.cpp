#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//global variable
string ans;
// Structures to organize student and course data
struct Student {
  string firstName;
  string lastName; 
  int id;
  string department;
  int year;
};
struct Course {
  string code;
  int creditHours;
  float grade;
  int year;
  string semester;  
};
void getStudentData(Student&);
void getCourseData(Course[], int&); 
void displayReport(Student, Course[], int);

int main() {
  Student student;  
  Course courses[100];
  int count = 0;
  getStudentData(student);
  getCourseData(courses, count);
  displayReport(student, courses, count);
  // File management
  ofstream outfile;
  outfile.open("student_report.txt");
  outfile << "Student Report" << endl;
  outfile << "Name: " << student.firstName << " " << student.lastName << endl;
  outfile << "ID: " << student.id << endl;
  outfile << "Department: " << student.department << endl;
  outfile << "Year of admission: " << student.year << endl;
  outfile << "Courses taken: " << endl;
  for (int i = 0; i < count; i++) {
    outfile << courses[i].code << " (" << courses[i].semester << " " << courses[i].year << ") - " << courses[i].creditHours << " credits, Grade: " << courses[i].grade << endl;
  }
  outfile.close();
  return 0;
}

void getStudentData(Student& s) {
  cout << "Enter student first name: ";
  cin >> s.firstName;
  cout << "Enter student last name: "; 
  cin >> s.lastName;
  cout << "Enter student ID: ";
  cin >> s.id;
  cout << "Enter student department: ";
  cin >> s.department;
  cout << "Enter student year of admission: ";
  cin >> s.year;
}
// Get course data and add to array
void getCourseData(Course courses[], int& count) {
  do {
    Course course;
    cout << "Enter course code: ";
    cin >> course.code;
    cout << "Enter credit hours: ";
    cin >> course.creditHours;
    cout << "Enter grade out of 100 : ";
    cin >> course.grade;
    cout << "Enter year: ";
    cin >> course.year;
    cout << "Enter semester: ";
    cin >> course.semester;
    courses[count] = course;
    count++;
    cout << "Add another course? (Y/N) ";
    cin >> ans;
  } while (ans == "Y");
}
void displayReport(Student s, Course courses[], int count) {

  cout << "Student Report" << endl;
  cout << "Name: " << s.firstName << " " << s.lastName << endl;
  cout << "ID: " << s.id << endl;
  cout << "Department: " << s.department << endl;
  cout << "Year of admission: " << s.year << endl;
  cout << "Courses taken: " << endl;
  for (int i = 0; i < count; i++) {
    cout << courses[i].code << " (" << courses[i].semester << " " << courses[i].year << ") - " << courses[i].creditHours << " credits, Grade: " << courses[i].grade << endl;
  }
}
