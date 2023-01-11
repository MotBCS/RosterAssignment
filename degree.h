//
//  degree.h
//  Thomas_Mya_Scripting_and_ProgramingApp-c867
//
//  Created by Mya Thomas on 12/27/22.
//

#ifndef degree_h
#define degree_h
#include <string>

using namespace std;

// Degree Program Types //
enum DegreeProgram{
    SECURITY,
    NETWORK,
    SOFTWARE,
    UNDECIDED
    
};

// Creates a string for each degree type (Parallel array) //
static const string degreeTypeStrings[] = {
    "SECURITY",
    "NETWORK",
    "SOFTWARE",
    "UNDECIDED"
};


#endif /* degree_h */
