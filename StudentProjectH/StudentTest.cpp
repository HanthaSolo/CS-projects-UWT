/* Rohan Seam and Hantha Nyunt
 * 11/16/2018
 * TCES 203
 * Programming Assignment #4
 *
 * The function of this program is to create and test various functions
 * create, modify, and print numerous Student objects.
*/

#include "Student.h"
#include <iostream>
using namespace std;

// Prototypes to test the 3 types of Constructors of Student
void testDefaultStudent();
void testStudentArray();
void testCopyStudent();

// Tests output of different types of Students
void testDefaultPrint();
void testArgumentPrint();

// Tests to verify functionality of modifying the name and hobby
// values
void testChangeName();
void testChangeHobby();

// Tests the getter functions to retrieve information about the
// Student
void testGetName();
void testGetHobby();
void testGetId();

int main() {
    testDefaultStudent();
    testStudentArray();
    testCopyStudent();

    testDefaultPrint();
    testArgumentPrint();

    testChangeName();
    testChangeHobby();

    testGetName();
    testGetHobby();
    testGetId();
    return 0;
}

// Tests default Student Constructor and displays success message
void testDefaultStudent() {
    Student* test = new Student();
    cout << "Successfully created default Student!" << endl;
    delete test;
}

// Tests Students created with characteristics entered by the
// user.
// User also specifies how many Student objects to create.
// The information of each Student is then displayed
void testStudentArray() {
    int numOfStudents, i, studentId;
    cout << "Enter the number of Students: ";
    cin >> numOfStudents;
    Student* students[numOfStudents];
    cout << endl;
    for(i = 0; i < numOfStudents; i++) {
        string name, hobby;
        cout << "Enter a name for Student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter a hobby for Student " << i + 1 << ": ";
        getline(cin, hobby);
        cout << "Enter a student ID for Student " << i + 1 << ": ";
        cin >> studentId;
        students[i] = new Student(name, hobby, studentId);
        students[i]->displayInfo();
        cout << endl;
    }
    for(i = 0; i < numOfStudents; i++) {
        delete students[i];
    }
}

// Tests the function to copy one Student to another.
// Student information of both are displayed
void testCopyStudent() {
    string name = "testName";
    string hobby = "testHobby";
    Student testCopy = Student(name, hobby, 123);
    Student copytest = Student(testCopy);
    cout << "Student 1: " << endl;
    testCopy.displayInfo();
    cout << "\nStudent 2: " << endl;
    copytest.displayInfo();
}

// Tests printing Student information for default Student
void testDefaultPrint() {
    Student test;
    test.displayInfo();
}

// Tests printing Student information for Student with chosen
// arguments
void testArgumentPrint() {
    string name = "test name print";
    string hobby = "test hobby print";
    Student test(name, hobby, 321);
    test.displayInfo();
}

// Tests functionality of changing the name of a Student object.
// Displays info of Student before and after altering name
void testChangeName() {
    Student test;
    test.displayInfo();
    cout << "After changing name" << endl;
    string newName = "changedName";
    test.setName(newName);
    test.displayInfo();
}

// Tests functionality of changing the hobby of a Student object.
// Displays info of Student before and after altering hobby
void testChangeHobby() {
    Student test;
    test.displayInfo();
    cout << "After changing hobby" << endl;
    string newHobby = "changedHobby";
    test.setHobby(newHobby);
    test.displayInfo();
}

// Tests functionality of retrieving the name of a Student
// object
void testGetName() {
    string name = "test get name";
    string hobby = "test";
    Student test(name, hobby, 123);
    cout << "Getting name: " << test.getName() << endl;
}

// Tests functionality of retrieving the hobby of a Student
// object
void testGetHobby() {
    string name = "test";
    string hobby = "test get hobby";
    Student test(name, hobby, 123);
    cout << "Getting hobby: " << test.getHobby() << endl;
}

// Tests functionality of retrieving the student ID of a
// Student object
void testGetId() {
    string name = "test";
    string hobby = "test";
    Student test(name, hobby, 123);
    cout << "Getting student ID: " << test.getId() << endl;
}
