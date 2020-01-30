/* Rohan Seam and Hantha Nyunt
 * 11/16/2018
 * TCES 203
 * Programming Assignment #4
 *
 * The function of this program is to operate as functionality for a Student.
 * User can create Student with various constructors, set Student name, set
 * Student hobby, and display the information of the Student.
*/
#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

// Copy Constructor that initializes and populates the characteristics
// of the current Student to the characteristics of the parameter passed.
Student :: Student(const Student &other) {
    setName(other.fullName);
    setHobby(other.hobby);
    this->studentId = other.studentId;
}

// Constructor that initializes a Student based on the parameters passed
Student :: Student(string name, string hobby, int id) {
    studentId = id;
    setName(name);
    setHobby(hobby);
}

// Sets the name of the Student object with the parameter passed
void Student :: setName(const string newName) {
    fullName = newName;
}

// Sets the hobby of the Student object with the parameter passed
void Student :: setHobby(const string newHobby) {
    hobby = newHobby;
}

// Displays the information for a Student in the form
// name, hobby, id
void Student :: displayInfo() const {
    cout << "Student name: " << fullName << endl;
    cout << "Student hobby: " << hobby << endl;
    cout << "Student ID: " << studentId << endl << endl;
}
