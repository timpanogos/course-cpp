#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"

class Roster
{
private:
    int maxSize;
    int length;
    Student** classRosterArray;

public:
    Roster();
    Roster(int maxSize);
    ~Roster(void);
    Student* add(string id, string fname, string lname, string email, int age, int* days, DegreeProgram degree);
    Student* add(Student* student);
    void remove(string id);
    void printAll();
    void printAverageDaysInCourse(string id);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree);
    void printAStudent(Student* student);
    int getNumberOfStudents();
    Student* getStudentByIndex(int index);
};

#endif

