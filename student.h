//
//  student.h
//  C867 PA
//
//  Created by Lydia Strough on 5/6/21.
//

#ifndef student_h
#define student_h
#include "degree.h"
using namespace std;

class Student {
   public:
      string GetStudentID();
      string GetFName();
      string GetLName();
      string GetEmail();
      int GetAge();
      enum DegreeProgram GetDegProgram();
      int* GetNumCourseDays();
      
      void SetStudentID(string sID);
      void SetFName(string fN);
      void SetLName(string lN);
      void SetEmail(string em);
      void SetAge(int a);
      void SetDegProgram(DegreeProgram deg);
      void SetNumCourseDays(int courseDays[]);
    
      Student(string sID, string fN, string lN, string em, int a, int courseDays[], DegreeProgram deg);
      string ConvertEnum(DegreeProgram deg);           //Convert degree program from enum to string type
      void Print();
  private:
      string studentID;                                //Student ID number
      string fName;                                    //First Name
      string lName;                                    //Last Name
      string email;                                    //Email Address
      int age;                                         //Age
      int numCourseDays[3];                            //Number of days to complete a course
      DegreeProgram degreeProgram;                     //Degree Program
};

#endif /* student_h */
