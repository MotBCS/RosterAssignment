//
//  Roster.cpp
//  Thomas_Mya_Scripting_and_ProgramingApp-c867
//
//  Created by Mya Thomas on 12/27/22.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Roster.h"
#include "degree.h"
#include "Student.h"

using namespace std;


// parse method //
void Roster::parse(string studentData)
{
 
    size_t rhs = studentData.find(","); // Finds first comma
    string SID = studentData.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string fiName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string laName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string eAddress = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    // Adding STOD function to convert a string to a double //
    int stAge = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    
    DegreeProgram dP = SECURITY; // Default Value //
    
    if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') // if statement needs to be fixed!! //
        dP = SECURITY;
    else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O')
        dP = SOFTWARE;
    else if (studentData.at(lhs) == 'N')
        dP = NETWORK;
    
    add(
        SID,
        fiName,
        laName,
        eAddress,
        stAge,
        daysInCourse1,
        daysInCourse2,
        daysInCourse3,
        dP);
}


void Roster::add(
                 string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram dP){
    
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, dP);
}
// (Revision) Using a call to print() to display student data //
void Roster::printAll(){
    for (int i = 0; i <= this->lastIndex; i++){
        (this->classRosterArray)[i]->print();
    }
}
// Displaying all student data //
/*void Roster::printAll(){
    for (int i = 0; i <= Roster::lastIndex; i++){
        cout << classRosterArray[i]->getSID(); cout << '\t';
        cout << classRosterArray[i]->getFName(); cout << '\t';
        cout << classRosterArray[i]->getLName(); cout << '\t';
        //cout << classRosterArray[i]->getEmail(); cout << '\t';
        cout << classRosterArray[i]->getAge(); cout << '\t';
        cout << classRosterArray[i]-> getAveDays()[0]; cout << ',';
        cout << classRosterArray[i]-> getAveDays()[1]; cout << ',';
        cout << classRosterArray[i]-> getAveDays()[2]; cout << '\t';
        cout << degreeTypeStrings[classRosterArray[i]->getDegreeProgram()] << endl;
    }
}
*/
// Displays students with matching degree program //
void Roster::printByDegreeProgram(DegreeProgram dP){
    for (int i = 0; i <= Roster::lastIndex; i++){
        if (Roster::classRosterArray[i]->getDegreeProgram() == dP) classRosterArray[i]->print();
    }
    cout << endl;
}

// Printing invalid emails (valid emails include -> @ and a(.), no white spaces include in email address) //

void Roster::printInvalidEmails(){
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++){
        string emailAddress = (classRosterArray[i]->getEmail());
        if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)){
            any = true;
            cout << emailAddress << " - is invalid" << endl;
        }
    }
    if (!any)
        cout << "NONE" << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getSID() == studentID)
        {
            cout << "STUDENT ID: "<< studentID << " AVERAGE DAYS IN COURSE: ";
            cout << (classRosterArray[i]->getAveDays()[0] + classRosterArray[i]->getAveDays()[1] + classRosterArray[i]->getAveDays()[2]) / 3 << endl;
        }
    }
}


void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getSID() == studentID)
        {
            success = true;
            if (i < studentDataTable - 1)
            {
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
            }
            Roster::lastIndex--; // Hide student but do not destroy student data //
        }
    }
    if (success)
    {
        cout << studentID << " has been removed from roster." << endl;
        this->printAll(); // Will display all students except for the recently removed student //
    }
    else
        cout << "STUDENT WITH ID: " << studentID << "not found..." << endl;
}

// Removes objects //
Roster::~Roster()
{
    cout << "Destructor called!" <<endl;
    for (int i = 0; i < studentDataTable; i++){}
}

