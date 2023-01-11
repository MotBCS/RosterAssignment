//
//  Student.h
//  Thomas_Mya_Scripting_and_ProgramingApp-c867
//
//  Created by Mya Thomas on 12/27/22.
//

#ifndef Student_h
#define Student_h

#include "degree.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Student
{
public:
    const static int dayArray = 3;
public:
    // Default constructor (leave empty)//
    Student();
    
    // Parameterized constructor //
    Student(
            string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int aveDays[],
            DegreeProgram degree);
    
    // Destructror //
    ~Student();
    
    
    // Getter (accessor) Functions //
    string getSID();
    string getFName();
    string getLName();
    string getEmail();

    int getAge();
    int* getAveDays();
    DegreeProgram getDegreeProgram();
    
    // Setter (mutator) Functions //
    void setSID(string studentID);
    void setFName(string firstName);
    void setLName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setAveDays(int aveDays[]);
    void setDegreeProgram(DegreeProgram dP);
    
    // Local Functions //
    void print();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    
    int age;
    int aveDays[dayArray];
    
    DegreeProgram degree; // Enum //
};




#endif /* Student_h */
