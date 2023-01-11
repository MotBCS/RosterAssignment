//
//  Roster.h
//  Thomas_Mya_Scripting_and_ProgramingApp-c867
//
//  Created by Mya Thomas on 12/27/22.
//

#ifndef Roster_h
#define Roster_h
#include "degree.h"
#include "Student.h"
#include <string>

using namespace std;

class Roster
{
public:
    int lastIndex = -1; // Goes through student data
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable];
    
public:
    void parse(string row); // seperates each field by the comma (pulls apart data)
    void add(
             string stID,
             string fiName,
             string laName,
             string eAddress,
             int stAge,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram dP);
    
    
    void printAll(); // Prints complete list of student data
    void removeStudentByID(string studentID); // Removes student from roster by student ID //
    void printAverageDaysInCourse(string studentID); // Print students average number of days in the three courses
    void printByDegreeProgram(DegreeProgram dP); // Prints degree
    void printInvalidEmails(); // Displays all invalid email addresses to user
    
    ~Roster();
};


#endif /* Roster_h */
