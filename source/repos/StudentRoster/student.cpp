#include <iostream>
#include "degree.h"
#include "student.h"
#include <new>

/* ****************************************************************************
* Constructors/Destructor
* ****************************************************************************/

Student::Student(const Student* student){
    id = student->id;
    fname = student->fname;
    lname = student->lname;
    email = student->email;
    age = student->age;
    days = new unsigned short[3];
    for (int i = 0; i < 3; i++) {
        days[i] = student->days[i];
    }
    degree = student->degree;
};

Student::Student(
    const string studentId,
    const string firstName,
    const string lastName,
    const string studentEmail,
    const unsigned char studentAge,
    const unsigned short* daysTaken,
    const DegreeProgram degreeProgram)
{
    if (studentId.length() < 2)
        throw(string("student id must be at least 2 characters: " + studentId));
    if (firstName.length() < 2)
        throw(string("first name must be at least 2 characters: " + firstName));
    if (lastName.length() < 2)
        throw(string("last name must be at least 2 characters: " + lastName));
    if(DEVELOPMENT_MODE)
        validateEmail(studentEmail); // the required functionality needs to allow invalid emails to be entered ... see Roster::printInvalidEmails();
    if (studentAge < 5 || studentAge > 100)
        throw(string("student age must be more than 4 and less than or equal to 100: " + studentAge));
    validateDays(daysTaken);

    id = studentId;
    fname = firstName;
    lname = lastName;
    email = studentEmail;
    age = studentAge;
    days = new unsigned short[3];
    for (int i = 0; i < 3; i++) {
        days[i] = daysTaken[i];
    }
    degree = degreeProgram;
}

Student::~Student()
{
    //delete[] days;
}

/* ****************************************************************************
* Validator functions
* ****************************************************************************/

void Student::validateDays(const unsigned short* daysTaken) {
    try {
        for(int i = 0; i < NUMBER_OF_PROGRAMS; i++) {
            int day = daysTaken[i];
            if(day < 0 || day > MAXDAYS)
                throw(day);
        }
    }
    catch (...) {
        throw(string("daysTaken must be a unsigned short array of length: " + to_string(NUMBER_OF_PROGRAMS) + " where each day is more than 0 and less than or equal to " + to_string(MAXDAYS)));
    }
}

void Student::validateEmail(const string email) {
    if (email.length() < 5)
        throw(string("student email must be at least 5 characters: " + email)); // a@b.c min
    string attaboy = string("@");
    string period = string(".");
    string space = string(" ");
    size_t attaboyIdx = email.find(attaboy);
    if (attaboyIdx == string::npos)
        throw(string("student email must contain a @: " + email));
    size_t periodIdx = email.find(period, attaboyIdx);
    if (periodIdx == string::npos)
        throw(string("student email must contain a period following the @: " + email));
    attaboyIdx = email.find(attaboy, ++attaboyIdx);
    if (attaboyIdx != string::npos)
        throw(string("student email must contain only 1 @: " + email));
    size_t spaceIdx = email.find(space); 
    if (spaceIdx != string::npos)
        throw(string("student email must not contain a space: " + email));
}

/* ****************************************************************************
* Getters
* ****************************************************************************/

const string Student::getId() { return id; }
const string Student::getFirstName() { return fname; }
const string Student::getLastName() { return lname; }
const string Student::getEmail() { return email; }
unsigned char Student::getAge() { return age; }
const unsigned short* Student::getDays() {
    return days; 
}
unsigned short Student::getDay(DegreeProgram degree) {
    int index;
    switch (degree) {
        case DegreeProgram::SECURITY:
            index = 0;
            break;
        case DegreeProgram::NETWORK:
            index = 1;
            break;
        case DegreeProgram::SOFTWARE:
            index = 2;
            break;
        default:
            throw(string("unknown degree"));
    }
    return days[index];
}
const DegreeProgram Student::getDegree() { return degree; }

/* ****************************************************************************
* Setters
* ****************************************************************************/

void Student::setId(string value) {
    if (value.length() < 2)
        throw(string("student id must be at least 2 characters: " + value));
    id = value; 
}

void Student::setFirstName(string value) { 
    if (value.length() < 2)
        throw(string("first name must be at least 2 characters: " + value));
    fname = value;
}

void Student::setLastName(string value) { 
    if (value.length() < 2)
        throw(string("last name must be at least 2 characters: " + value));
    lname = value;
}

void Student::setEmail(string value) { 
    validateEmail(value);
    email = value;
}

void Student::setAge(const unsigned char value) {
    if (value < 5 || value > 100)
        throw(string("student age must be more than 4 and less than or equal to 100: " + value));
    age = value;
}

void Student::setDays(const unsigned short* value) {
    validateDays(value);
    days = new unsigned short[NUMBER_OF_PROGRAMS];
    for (int i = 0; i < 3; i++)
        days[i] = value[i];
}

void Student::setDegree(const DegreeProgram value) { degree = value; }


