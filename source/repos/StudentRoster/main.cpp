// StudentRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"

bool developmentMode = false;  // set me false for function requirements runs

/* ****************************************************************************
* Initialization helper functions
* ****************************************************************************/

Student* getStudent(int index) {
    /*
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Chase,Adams,japanadams@gmail.com,36, 31,32,33,SOFTWARE"
        */
    int days0[]{ 30, 35, 40 };
    int days1[]{ 50, 30, 40 };
    int days2[]{ 20, 40, 33 };
    int days3[]{ 50, 58, 40 };
    int days4[]{ 31, 32, 33 };
    switch (index) {
        case 0:
            return new Student("A1", "John", "Smith", "John1989@gmail.com", 20, days0, DegreeProgram::SECURITY);
        case 1:
            if(!developmentMode)
                return new Student("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, days1, DegreeProgram::NETWORK);
            else
                return new Student("A2", "Suzan", "Erickson", "Erickson_1990@gmail.com", 19, days1, DegreeProgram::NETWORK);
        case 2:
            if (!developmentMode)
                return new Student("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, days2, DegreeProgram::SOFTWARE);
            else
                return new Student("A3", "Jack", "Napoli", "The_lawyer99@yahoo.com", 19, days2, DegreeProgram::SOFTWARE);
        case 3:
            return new Student("A4", "Erin", "Black", "Erin.black@comcast.net", 22, days3, DegreeProgram::SECURITY);
        case 4:
            return new Student("A5", "Chase", "Adams", "japanadams@gmail.com", 36, days4, DegreeProgram::SOFTWARE);
        default:
            throw(string("getStudent called with an invalid index: " + index));
    }
}

void addAllStudents(Roster* roster) {
    roster->add(getStudent(0));
    roster->add(getStudent(1));
    roster->add(getStudent(2));
    roster->add(getStudent(3));
    roster->add(getStudent(4));
}

Roster* init(int maxStudents) {
    Roster* roster = new Roster(maxStudents);
    addAllStudents(roster);
    return roster;
}

/* ****************************************************************************
* Development test functions follow
* ****************************************************************************/

void removeTest(Roster* roster) {
    string errMsg = "";
    // test a bad student ID
    try {
        roster->remove("badId");
        errMsg = "remove expected a not found exception";
    }
    catch (string errMsg) {
    }
    if (errMsg.length() != 0)
        throw(string(errMsg));
    
    // test removing the top index, result = [a1,a2,a3,a4]
    roster->remove("A5");
    int size = roster->getNumberOfStudents();
    if (size != 4)
        throw(string("Expected 4 students got: " + size));

    // test removing the next to top index, result = [a1,a2,a4]
    roster->remove("A3");
    size = roster->getNumberOfStudents();
    if (size != 3)
        throw(string("Expected 3 students got: " + size));

    // test removing the bottom index, result = [a2,a4]
    roster->remove("A1");
    size = roster->getNumberOfStudents();
    if (size != 2)
        throw(string("Expected 2 students got: " + size));

    // test removing the bottom index again, result = [a4]
    roster->remove("A2");
    size = roster->getNumberOfStudents();
    if (size != 1)
        throw(string("Expected 1 students got: " + size));

    // test removing the last index, result = []
    roster->remove("A4");
    size = roster->getNumberOfStudents();
    if (size != 0)
        throw(string("Expected 0 students got: " + size));
    // set things back to init state
    addAllStudents(roster);
    size = roster->getNumberOfStudents();
    if (size != 5)
        throw(string("Expected 5 students got: " + size));
}

void validateAnEmailTest(Student* student, string email) {
    string errMsg = "";
    try {
        student->validateEmail(email);
        errMsg = "validateEmail expected an exception";
    }
    catch (string errMsg) {
    }
    if (errMsg.length() != 0)
        throw(string(errMsg));
}

void validateEmailTest() {
    Student* student = getStudent(0);
    validateAnEmailTest(student, "a@b."); // too few characters
    validateAnEmailTest(student, "The_lawyer99yahoo.com"); // missing @
    validateAnEmailTest(student, "Erickson_1990@gmailcom"); // missing .
    validateAnEmailTest(student, "Erickson.1990@gmailcom"); // missing . following @
    validateAnEmailTest(student, "Erickson@1990@gmail.com"); // more than 1 @
    student->validateEmail("Erickson.1990@gmail.com");  // valid one
}

void validateADaysTest(Student* student, int* days) {
    string errMsg = "";
    try {
        student->validateDays(days);
        errMsg = "validateDays expected an exception";
    }
    catch (string errMsg) {
    }
    if (errMsg.length() != 0)
        throw(string(errMsg));
}

void validateDaysTest() {
    Student* student = getStudent(0);
    int ok[]{ 30, 35, 40 };
    int tooFew[]{ 30, 35};
    int tooLow0[]{ 0, 35, 40 };
    int tooHi0[]{ 101, 35, 40 };
    int tooLow1[]{ 30, 0, 40 };
    int tooHi1[]{ 30, 101, 40 };
    int tooLow2[]{ 30, 35, 0 };
    int tooHi2[]{ 30, 35, 101 };

    validateADaysTest(student, tooFew);
    validateADaysTest(student, tooLow0);
    validateADaysTest(student, tooHi0);
    validateADaysTest(student, tooLow1);
    validateADaysTest(student, tooHi1);
    validateADaysTest(student, tooLow2);
    validateADaysTest(student, tooHi2);
    student->validateDays(ok);
}

/* ****************************************************************************
* Main entry point function
* ****************************************************************************/

int main()
{
    Roster* roster = NULL;
    try {
        roster = init(40);
        if(developmentMode) {
            removeTest(roster);
            validateEmailTest();
            validateDaysTest();
        }
        else {
            roster->printInvalidEmails();
        }
        delete roster;
    }
    catch (string errMsg) {
        cout << errMsg;
        if (roster)
            delete roster;
        return 1;
    }
    catch (...) {
        cout << "default exception caught";
        if (roster)
            delete roster;
        return 1;
    }
    return 0;
}
