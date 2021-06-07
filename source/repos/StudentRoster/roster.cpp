#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <new>

/* ****************************************************************************
* Constructors/Destructor 
* ****************************************************************************/

Roster::Roster()
{
    length = 0;
    maxSize = 45;
    classRosterArray = new Student * [maxSize];
}

Roster::Roster(int maximumSize)
{
    length = 0;
    maxSize = maximumSize;
    classRosterArray = new Student * [maxSize];
}

Roster::~Roster()
{
    for (int i = 0; i < length; i++) {
        Student* student = classRosterArray[i];
        classRosterArray[i] = NULL;
        delete student;
    }
    delete[] classRosterArray;
}

/* ****************************************************************************
* Course functionality required functions
* ****************************************************************************/

Student* Roster::add(Student* student) {
    if (length == maxSize)
        throw(string("The student roster is full, size: " + maxSize));
    classRosterArray[length++] = student;
    return student;
}

Student* Roster::add(string id, string fname, string lname, string email, int age, int* days, DegreeProgram degree) {
    if (length == maxSize)
        throw(string("The student roster is full, size: " + maxSize));
    Student* student = new Student(id, fname, lname, email, age, days, degree);
    classRosterArray[length++] = student;
    return student;
}

void Roster::remove(string studentId) {
    int deleteIdx = -1;
    Student* student = NULL;
    for (int i = 0; i < length; i++) {
        student = classRosterArray[i];
        if (student->getId().compare(studentId) == 0) {
            deleteIdx = i;
            break;
        }
    }
    if (deleteIdx == -1)
        throw(string("The given Student ID is not found in the roster, id: " + studentId));

    classRosterArray[deleteIdx] = NULL;
    delete student;
    --length;
    if (deleteIdx == length) {
        // the removed student was at the arrays top index, nothing needs moved in the array
        return;
    }
    // move everything above deleteIdx down one to fill the hole we just created.
    for (int i = deleteIdx; i < length; i++) {
        classRosterArray[i] = classRosterArray[i + 1];
    }
    classRosterArray[length] = NULL; // [i + 1] in above for loop move the previous topIndex to the new top, null out the old one 
}

void Roster::printAll() {

}

void Roster::printAverageDaysInCourse(string id) {

}

void Roster::printInvalidEmails() {
    cout << "The following Students have an invalid email\n";
    Student* student;
    for (int i = 0; i < length; i++) {
        try {
            student = classRosterArray[i];
            student->validateEmail(student->getEmail());
        }
        catch (string errMsg) {
            Roster::printAStudent(student);
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degree) {

}

void Roster::printAStudent(Student* student) {
    string id = student->getId();
    string msg =
        "Student ID: " + id + "\n" +
        "First Name: " + student->getFirstName() + "\n" +
        "Last Name: " + student->getLastName() + "\n" +
        "Email: " + student->getEmail() + "\n" +
        "Age: " + to_string(student->getAge()) + "\n" +
        "Days Taken: [";
        msg = msg + to_string(student->getDay(0)) + ", ";
        msg = msg + to_string(student->getDay(1)) + ", ";
        msg = msg + to_string(student->getDay(2)) + "]\n";

    string degree = "";
    switch (student->getDegree()) {
    case DegreeProgram::SECURITY:
        degree = "SECURITY";
        break;
    case DegreeProgram::NETWORK:
        degree = "NETWORK";
        break;
    case DegreeProgram::SOFTWARE:
        degree = "SOFTWARE";
        break;
    }
    msg = msg + "Degree Program: " + degree + "\n\n";
    cout << msg;
}

/* ****************************************************************************
* Development/Experimental functions
* ****************************************************************************/

Student* Roster::getStudentByIndex(int index) {
    if (length == 0 || index < 0 || index > length - 1)
        throw(string("invalid index: " + index));
    return classRosterArray[index];
}

int Roster::getNumberOfStudents() {
    return length;
}

