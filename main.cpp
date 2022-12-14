//
//  main.cpp
//  C867 PA
//
//  Created by Lydia Strough on 5/6/21.
//

#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
//Student Data Table
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Lydia,Strough,lstroug@wgu.edu,25,27,25,19,SOFTWARE"
    };
//End of Student Data Table
    
//Course Title
    cout << "C867-Scripting & Programming Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 2452624" << endl;
    cout << "Name: Lydia Strough" << endl;
    cout << endl;
//End of Course Title
 
   Roster classRoster;
    
   for (int i = 0; i < 5; i++) {
        classRoster.Parse(studentData[i]);
    }
    
    cout << "Display all students:" << endl;
    classRoster.PrintAll();
    cout << endl;
    
    cout << "Displaying invalid emails: " << endl;
    cout << endl;
    classRoster.PrintInvalidEmails();
    cout << endl;
    
    for (int i = 0; i < 5; i++) {
        classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
     }
    cout << endl;
    
    cout << "Showing students in degree program: SOFTWARE" << endl;
    cout << endl;
    classRoster.PrintByDegreeProgram(SOFTWARE);
    cout << endl;
    
    cout << "Removing A3:" << endl;
    cout << endl;
    classRoster.Remove("A3");
    classRoster.PrintAll();
    cout << endl;
    
    cout << "Removing A3 again" << endl;
    cout << endl;
    classRoster.Remove("A3");
    
    cout << "DONE." << endl;
    
    return 0;
}
