//
//  main.cpp
//  Thomas_Mya_Scripting_and_ProgramingApp-c867
//
//  Created by Mya Thomas on 12/27/22.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Roster.h"

using namespace std;

int main()
{
    // Program Header Title //
    cout << endl;
    cout << "*************************************************************" << endl;
    cout << "* * Course: Scripting and Programming - Applications C867 * *" << endl;
    cout << "* *               Programming Language: C++               * *" << endl;
    cout << "* *                 Student ID: 010507144                 * *" << endl;
    cout << "* *                  Student: Mya Thomas                  * *" << endl;
    cout << "*************************************************************" << endl;
    
    // Student Data Table //
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Mya ,Thomas,mth1759@gmail.com,23,20,30,33,SOFTWARE"
    };
    
    const int studentDataTable = 5; // Array Size //
    Roster Roster;
    
    for (int i = 0; i < studentDataTable; i++)
        Roster.parse(studentData[i]);
    // Displaying all students included in data table //
    cout << endl;
    cout << "** DISPLAYING ALL STUDENTS: " << endl;
    Roster.printAll();
    cout << endl;
    
    cout << endl;
    cout << endl;
    
    // Displaying any invalid student email addresses //
    cout << "** DISPLAYING INVALID EMAIL ADDRESSES: " << endl;
    cout << endl;
    Roster.printInvalidEmails();
    
    cout << endl;
    cout << endl;
    
    // Displaying average days for three classes per a student //
    cout << "** DISPLAYING AVERAGE DAYS IN COURSE: " << endl;
    cout << endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        Roster.printAverageDaysInCourse(Roster.classRosterArray[i]->getSID());
    }

    cout << endl;
    cout << endl;
    
    // Displaying all students in the SOFTWARE degree program //
    cout << "** DISPLAYING ALL SOFTWARE STUDENTS: " << endl;
    cout << endl;
    Roster.printByDegreeProgram(SOFTWARE);
    //Roster.printAll();
    
    cout << endl;
    cout << endl;
    
    // Removing student with ID A3 //
    cout << "** REMOVING STUDENT WITH ID : A3 " << endl;
    cout << endl;
    Roster.removeStudentByID("A3");
    //Roster.printAll();
    
    cout << endl;
    cout << endl;
    
    // Attempting to remove student with ID A3 again //
    cout << "** REMOVING STUDENT WITH ID : A3 AGAIN..." << endl;
    cout << endl;
   Roster.removeStudentByID("A3 ");
    
    cout << endl;
    cout << endl;
    
    
    // Remember to implement the destructor to release the memory that was allocated dynamically in Roster //
    
    cout << "DONE" << endl;
    return 0;
}
