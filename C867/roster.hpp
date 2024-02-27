//
//  roster.hpp
//  C867
//
//  Created by Samuel Phillips on 2/22/24.
//

#ifndef roster_hpp
#define roster_hpp
#pragma once

#include <stdio.h>
#include <iostream>
#include <cstring>
#include "student.hpp"

class Roster {
    public:
        Student * classRosterArray[5];
        void parse(std::string studentData);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram);
};

#endif /* roster_hpp */
