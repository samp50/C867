//
//  roster.cpp
//  C867
//
//  Created by Samuel Phillips on 2/22/24.
//

#include "roster.hpp"
#include "student.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <variant>
#pragma once

// This should parse the whole string by comma,
// then it adds each value

void Roster::parse(std::string studentData) {
    std::istringstream ss(studentData);
    std::string token;
    using samsVariant = std::variant<std::string, int, DegreeProgram>;
    std::vector<samsVariant> studentDataList;
    
    while (std::getline(ss, token, ',')) {
        //std::cout << token << std::endl;
        studentDataList.push_back(token);
    }
    
    // Test code to print values of item added to list -- works!
    /*
    for (const auto& item : studentDataList) {
            std::visit([](const auto& value) {
                std::cout << "Value: " << value << std::endl;
            }, item);
        }
    */
    for (const auto& item : studentDataList) {
        std::visit([](const auto& value) {
            using ValueType = std::decay_t<decltype(value)>; // Get the underlying type

            std::cout << "Type: " << typeid(ValueType).name() << ", Value: " << value << std::endl;
        }, item);
    }
    
    //add(std::get<std::string>(studentDataList[0]), std::get<std::string>(studentDataList[1]), std::get<std::string>(studentDataList[2]), std::get<std::string>(studentDataList[3]), std::get<int>(studentDataList[4]), std::get<int>(studentDataList[5]), std::get<int>(studentDataList[6]), std::get<int>(studentDataList[7]), std::get<DegreeProgram>(studentDataList[8]));
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram) {
    //Student * S = new Student(studentID, firstName, lastName, email, age, daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3, degreeProgram);
    
}
