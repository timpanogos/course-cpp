#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;

/// <summary>
/// The Student class's daysTaken array elements must be values between 0 and MAXDAYS inclusive.
/// </summary>
const unsigned short MAXDAYS = 365;

class Student
{
private:
    string id;
    string fname;
    string lname;
    string email;
    unsigned char age;
    unsigned short* days;
    DegreeProgram degree;

public:
    /// <summary>
    /// copy constructor which is used by various setter methods to isolate the
    /// callers student pointer from this students state.
    /// The caller maintains ownership of the incoming student parameter pointer
    /// and cleaning it up as needed.
    /// </summary>
    /// <param name="student">the student object pointer to be cloned.</param>
    Student(const Student* student);

    /// <summary>
    /// Instantiate a new student with the given paramaters.
    /// </summary>
    /// <param name="id">a string that is unique within this applications scope.</param>
    /// <param name="fname">the students first name.</param>
    /// <param name="lname">the students last name.</param>
    /// <param name="email">the students email.</param>
    /// <param name="age">the students age.</param>
    /// <param name="days">
    /// an array of unsigned short values that corrispond with the elements of the DegreeProgram enum.
    /// The values of the elements must be between 0 and MAXDAYS where 0 indicates never enrolled.
    /// </param>
    /// <param name="degree">The DegreeProgram that this student is in.</param>
    Student(
        const string id, const string fname, const string lname, const string email, 
        const unsigned char age, const unsigned short* days, const DegreeProgram degree);
    
    ~Student(void);

    /// <summary>
    /// return this students ID.
    /// </summary>
    /// <returns>the string id field of this object.</returns>
    const string getId();

    /// <summary>
    /// return this students first name.
    /// </summary>
    /// <returns>the string fname field of this object.</returns>
    const string getFirstName();

    /// <summary>
    /// return this students last name.
    /// </summary>
    /// <returns>the string lname field of this object.</returns>
    const string getLastName();

    /// <summary>
    /// return this students email address.
    /// </summary>
    /// <returns>the string email field of this object.</returns>
    const string getEmail();

    /// <summary>
    /// return this students age.
    /// </summary>
    /// <returns>the unsigned char age field of this object.</returns>
    unsigned char getAge();

    /// <summary>
    /// returns an array of the same number of elements as NUMBER_OF_PROGRAMS.  
    /// The value of each index of the returned array corrispond to the same index of the DegreeProgram enum.
    /// Each of the values represent the number of days it took this student to finish the associated degree. 
    /// </summary>
    /// <returns> the unsigned short array daysTaken field of this object.</returns>
    const unsigned short* getDays();

    /// <summary>
    /// returns the number of days for the requested DegreeProgram.
    /// </summary>
    /// <param name="index"></param>
    /// <returns>unsigned short which is the number of days in the requested degree</returns>
    unsigned short getDay(DegreeProgram degree);

    /// <summary>
    /// returns this students currently active degree.
    /// </summary>
    /// <returns></returns>
    const DegreeProgram getDegree();

    /// <summary>
    /// sets this students id field to the given value.
    /// </summary>
    /// <param name="value">the string value to set.</param>
    void setId(const string value);

    /// <summary>
    /// sets this students fname field to the given value.
    /// </summary>
    /// <param name="value">the string value to set.</param>
    void setFirstName(const string value);

    /// <summary>
    /// sets this students lname field to the given value.
    /// </summary>
    /// <param name="value">the string value to set.</param>
    void setLastName(const string value);

    /// <summary>
    /// sets this students email field to the given value. Throws an exception if invalid.
    /// </summary>
    /// <param name="value">the string value to set.</param>
    void setEmail(const string value);

    /// <summary>
    /// sets this students age field to the given value.
    /// </summary>
    /// <param name="value">the unsigned char value to set.</param>
    void setAge(const unsigned char value);

    /// <summary>
    /// sets this students days field to a clone of the given value.  The caller maintains ownership of the input value. Throws an exception if invalid.
    /// </summary>
    /// <param name="value">the unsigned short[] to be cloned and set.</param>
    void setDays(const unsigned short *value);

    /// <summary>
    /// sets this students degree field to the given value.
    /// </summary>
    /// <param name="value">the DegreeProgram value to set.</param>
    void setDegree(const DegreeProgram value);

    /// <summary>
    /// check the given email for validity. Throws an exception if invalid.
    /// </summary>
    /// <param name="email">the string value to be checked.</param>
    void validateEmail(const string email);

    /// <summary>
    /// check the given days as being validity. Throws an exception if invalid.
    /// </summary>
    /// <param name="days">the unsigned short array to be checked.</param>
    void validateDays(const unsigned short* days);
};

#endif