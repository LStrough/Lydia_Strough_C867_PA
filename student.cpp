//
//  student.cpp
//  C867 PA
//
//  Created by Lydia Strough on 5/6/21.
//

#include <iostream>
#include <string>
#include "student.h"
using namespace std;

string Student::GetStudentID() {
    return studentID;
}

string Student::GetFName() {
    return fName;
}

string Student::GetLName() {
    return lName;
}

string Student::GetEmail() {
    return email;
}

int Student::GetAge() {
    return age;
}

enum DegreeProgram Student::GetDegProgram() {
    return degreeProgram;
}

int* Student::GetNumCourseDays() {
    return numCourseDays;
}

void Student::SetStudentID(string sID) {
    studentID = sID;
    
    return;
}

void Student::SetFName(string fN) {
    fName = fN;
    
    return;
}

void Student::SetLName(string lN) {
    lName = lN;
    
    return;
}

void Student::SetEmail(string em) {
    email = em;
    
    return;
}

void Student::SetAge(int a) {
    age = a;
    
    return;
}

void Student::SetDegProgram(DegreeProgram deg) {
    degreeProgram = deg;
    
    return;
}

void Student::SetNumCourseDays(int courseDays[]) {
    for(int i = 0; i < 3; i++) {
        numCourseDays[i] = courseDays[i];
    }
    
    return;
}

Student::Student(string sID, string fN, string lN, string em, int a, int courseDays[], DegreeProgram deg) {
    SetStudentID(sID);
    SetFName(fN);
    SetLName(lN);
    SetEmail(em);
    SetAge(a);
    SetNumCourseDays(courseDays);
    SetDegProgram(deg);
    
    return;
}

string Student::ConvertEnum(DegreeProgram deg){
    if(deg == SOFTWARE) {
        return "SOFTWARE";
    }
    else if(deg == NETWORK) {
        return "NETWORK";
    }
    else {
        return "SECURITY";
    }
}

void Student::Print() {
    cout << GetStudentID() << "\t\t";
    cout << GetFName() << "\t\t";
    cout << GetLName() << "       \t";
    cout << GetEmail() << "     \t";
    cout << GetAge() << "\t\t";
    cout << "{" << GetNumCourseDays()[0] << "," << GetNumCourseDays()[1] << "," << GetNumCourseDays()[2] << "}" << "\t\t";
    cout << ConvertEnum(GetDegProgram()) << endl;
    
    return;
}








