//
//  roster.h
//  C867 PA
//
//  Created by Lydia Strough on 5/6/21.
//

#ifndef roster_h
#define roster_h
#include "student.h"
using namespace std;

class Roster {
   public:
      void Parse(string row);                      
      void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
      void Remove(string studentID);
      void PrintAll();
      void PrintAverageDaysInCourse(string studentID);
      void PrintInvalidEmails();
      void PrintByDegreeProgram(DegreeProgram degreeProgram);
      
      ~Roster();
      Student* classRosterArray[5];
   private:
      int numStudents = 5;
      int lastIndex = -1;                                
};

#endif /* roster_h */
