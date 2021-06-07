#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;

class Student
{
private:
    string id;
    string fname;
    string lname;
    string email;
    int age;
    int* daysTaken;
    DegreeProgram degree;

public:
    Student(Student* student);
    Student(string id, string fname, string lname, string email, int age, int* days, DegreeProgram degree);
    ~Student(void);
    string getId();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    int getDay(int index);
    DegreeProgram getDegree();
    void setId(string value);
    void setFirstName(string value);
    void setLastName(string value);
    void setEmail(string value);
    void setAge(int value);
    void setDays(int *value);
    void setDegree(DegreeProgram value);
    void validateEmail(string email);
    void validateDays(int* days);
};

#endif