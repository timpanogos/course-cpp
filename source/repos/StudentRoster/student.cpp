#include "degree.h"
#include "student.h"
#include <new>

/* ****************************************************************************
* Constructors/Destructor
* ****************************************************************************/

Student::Student(Student* student){
    id = student->id;
    fname = student->fname;
    lname = student->lname;
    email = student->email;
    age = student->age;
    daysTaken = new int[3];
    for (int i = 0; i < 3; i++) {
        daysTaken[i] = student->daysTaken[i];
    }
    degree = student->degree;
};

Student::Student(
    string studentId,
    string firstName,
    string lastName,
    string studentEmail,
    int studentAge,
    int* takenDays,
    DegreeProgram degreeProgram)
{
    if (studentId.length() < 2)
        throw(string("student id must be at least 2 characters: " + studentId));
    if (firstName.length() < 2)
        throw(string("first name must be at least 2 characters: " + firstName));
    if (lastName.length() < 2)
        throw(string("last name must be at least 2 characters: " + lastName));
    if(developmentMode)
        validateEmail(studentEmail); // the required functionality needs to allow invalid emails to be entered ... see Roster::printInvalidEmails();
    if (studentAge < 5 || studentAge > 100)
        throw(string("student age must be more than 4 and less than or equal to 100: " + studentAge));
    validateDays(takenDays);

    id = studentId;
    fname = firstName;
    lname = lastName;
    email = studentEmail;
    age = studentAge;
    daysTaken = new int[3];
    for (int i = 0; i < 3; i++) {
        daysTaken[i] = takenDays[i];
    }
    degree = degreeProgram;
}

Student::~Student()
{
    delete[] daysTaken;
}

/* ****************************************************************************
* Validator functions
* ****************************************************************************/

void Student::validateDays(int* days) {
    try {
        for(int i = 0; i < 3; i++) {
            int day = days[i];
            if(day < 1 || day > 90)
                throw(day);
        }
    }
    catch (...) {
        throw(string("takenDays must be an int array of length 3 where each day is more than 0 and less than or equal to 90"));
    }
}

void Student::validateEmail(string email) {
    if (email.length() < 5)
        throw(string("student email must be at least 5 characters: " + email)); // a@b.c min
    string attaboy = string("@");
    string period = string(".");
    size_t attaboyIdx = email.find(attaboy);
    if (attaboyIdx == string::npos)
        throw(string("student email must contain a @: " + email));
    size_t periodIdx = email.find(period, attaboyIdx);
    if (periodIdx == string::npos)
        throw(string("student email must contain a period following the @: " + email));
    attaboyIdx = email.find(attaboy, ++attaboyIdx);
    if (attaboyIdx != string::npos)
        throw(string("student email must contain only 1 @: " + email));
}

/* ****************************************************************************
* Getters
* ****************************************************************************/

string Student::getId() { 
    return id; 
}
string Student::getFirstName() { return fname; }
string Student::getLastName() { return lname; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
int* Student::getDays() { 
    return daysTaken; 
}
int Student::getDay(int index) { 
    if (index < 0 || index > 2)
        throw(string("index must be >= 0 and < 3 index: " + index));
    int day = *(daysTaken + index); 
    return day;
}
DegreeProgram Student::getDegree() { return degree; }

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

void Student::setAge(int value) {
    if (value < 5 || value > 100)
        throw(string("student age must be more than 4 and less than or equal to 100: " + value));
    age = value;
}

void Student::setDays(int* value) {
    validateDays(value);
    daysTaken = value;
}

void Student::setDegree(DegreeProgram value) { degree = value; }

