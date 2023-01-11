//
//  Student.cpp
//  Thomas_Mya_Scripting_and_ProgramingApp-c867
//
//  Created by Mya Thomas on 12/27/22.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

// Parameterless Constructor (do not include null pointers)//
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    
    for(int i = 0; i < dayArray; i++)
    {
        this->aveDays[i] = 0;
    }
    
    this->degree = DegreeProgram::SECURITY;
}

// Constructor //
Student::Student(
                 string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int aveDays[],
                 DegreeProgram degree){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    
    for(int i = 0; i < dayArray; i++)
    {
        this->aveDays[i] = aveDays[i];
    }
    
    this->degree = degree;
}

// Getter (accessor) Functions //
string Student::getSID() {return this->studentID;}
string Student::getFName() {return this-> firstName;}
string Student::getLName() {return this->lastName;}
string Student::getEmail() {return this-> emailAddress;}
int Student::getAge() {return this-> age;}
int* Student::getAveDays(){return this->aveDays;}
DegreeProgram Student::getDegreeProgram(){return this->degree;}

// Setter (mutator) Functions //
void Student::setSID(string studentID){this->studentID = studentID;}
void Student::setFName(string firstName){this->firstName = firstName;}
void Student::setLName(string lastName){this->lastName = lastName;}
void Student::setEmail(string emailAddress){this->emailAddress = emailAddress;}
void Student::setAge(int age){this->age = age;}
void Student::setAveDays(int aveDays[]){
    for(int i = 0; i < dayArray; i++)this->aveDays[i] = aveDays[i];
}
void Student::setDegreeProgram(DegreeProgram dP){this->degree = dP;}

void Student::print(){
    cout << this->getSID() << '\t';
    cout << this->getFName() << '\t';
    cout << this->getLName() << '\t';
    //cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this-> getAveDays()[0] << ',';
    cout << this-> getAveDays()[1] << ',';
    cout << this-> getAveDays()[2] << '\t';
    cout << degreeTypeStrings[this->getDegreeProgram()] << endl;
}

// Destructor //
Student::~Student(){}
