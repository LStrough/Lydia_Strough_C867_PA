//
//  roster.cpp
//  C867 PA
//
//  Created by Lydia Strough on 5/6/21.
//

#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

void Roster::Parse(string row) {
    size_t rhs = row.find(",");
    string studentID = row.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string firstName = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string lastName = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string degreeprogram = row.substr(lhs, rhs - lhs);
    
    DegreeProgram dp;
    if(degreeprogram == "SECURITY") {
        dp = SECURITY;
    }
    else if(degreeprogram == "NETWORK") {
        dp = NETWORK;
    }
    else {
        dp = SOFTWARE;
    }
    
    Add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
    
    return;
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    
    int NumCourseDays[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    lastIndex++;
    
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, NumCourseDays, degreeprogram);
    
    return;
}

void Roster::Remove(string studentID) {
    bool found = false;
    int i = 0;
    
    while(found != true && i < numStudents) {
        if(classRosterArray[i]->GetStudentID() == studentID) {
            delete classRosterArray[i];
            found = true;
            for(int j = i; j < numStudents - 1; j++){
                classRosterArray[j] = classRosterArray[j + 1];
            }
            numStudents--;
        }
        else {
            i++;
        }
    }
    
    if(found != true) {
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    }

    return;
}

void Roster::PrintAll() {
    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i]->Print();
    }
    
    return;
}

void Roster::PrintAverageDaysInCourse(string studentID) {
    int totalCourseDays = 0;
    int averageCourseDays;
    
    for(int i = 0; i < numStudents; i++) {
        if(classRosterArray[i]->GetStudentID() == studentID){
            totalCourseDays = classRosterArray[i]->GetNumCourseDays()[0] + classRosterArray[i]->GetNumCourseDays()[1] + classRosterArray[i]->GetNumCourseDays()[2];
        }
    }
    
    averageCourseDays = totalCourseDays / 3;
    
    cout << "Student ID: " << studentID << ", average days in course is: ";
    cout << averageCourseDays << endl;
    return;
}

void Roster::PrintInvalidEmails() {
    string test;
    
    for(int i = 0; i < numStudents; i++) {
        test = classRosterArray[i]->GetEmail();
        if(test.find(' ') != string::npos){
            cout << test << " - is invalid." << endl;
        }
        if(test.find('.') == string::npos){
            cout << test << " - is invalid." << endl;
        }
        if(test.find('@') == string::npos){
            cout << test << " - is invalid." << endl;
        }
    }
    
    return;
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    for(int i = 0; i < numStudents; i++){
        if(classRosterArray[i]->GetDegProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
    
    return;
}

Roster::~Roster() {
    for(int i = 0; i < numStudents; i++){
        delete classRosterArray[i];
    }
    
    return;
}


