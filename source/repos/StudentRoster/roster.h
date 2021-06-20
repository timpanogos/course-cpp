#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"

class Roster
{
private:
    unsigned short maxSize;
    unsigned short length;
    Student** classRosterArray;

public:
    Roster();
    Roster(const unsigned short maxSize);
    ~Roster(void);
    void add(
        const string id, const string fname, const string lname, const string email, 
        const unsigned char age, const unsigned short* days, const DegreeProgram degree);
    void add(const Student* student);
    void remove(const string id);
    void printAll();
    void printAverageDaysInCourse(const string id);
    void printInvalidEmails();
    void printByDegreeProgram(const DegreeProgram degree);
    void printAStudent(Student* student);
    int getNumberOfStudents();
    const Student* getStudentByIndex(const unsigned short index);
};

#endif

