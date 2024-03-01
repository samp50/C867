#include "roster.hpp"
#include "student.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <variant>
#include <typeinfo>

void Roster::parse(std::string studentData) {
    std::istringstream ss(studentData);
    std::string token;
    std::variant<std::string, int, DegreeProgram> studentDataArray[9];

    for (int i = 0; i < 9 && std::getline(ss, token, ','); ++i) {
        studentDataArray[i] = token;
    }

    if (std::getline(ss, token, ',')) {
        std::cerr << "Error: Unexpected number of elements in the input string." << std::endl;
        return;
    }

    try {
        std::string studentID = std::get_if<std::string>(&studentDataArray[0]) ? *std::get_if<std::string>(&studentDataArray[0]) : "";
        std::string firstName = std::get_if<std::string>(&studentDataArray[1]) ? *std::get_if<std::string>(&studentDataArray[1]) : "";
        std::string lastName = std::get_if<std::string>(&studentDataArray[2]) ? *std::get_if<std::string>(&studentDataArray[2]) : "";
        std::string email = std::get_if<std::string>(&studentDataArray[3]) ? *std::get_if<std::string>(&studentDataArray[3]) : "";

        int age = std::stoi(std::get<std::string>(studentDataArray[4]));
        int daysInCourse1 = std::stoi(std::get<std::string>(studentDataArray[5]));
        int daysInCourse2 = std::stoi(std::get<std::string>(studentDataArray[6]));
        int daysInCourse3 = std::stoi(std::get<std::string>(studentDataArray[7]));

        DegreeProgram degreeProgram;
        std::string degreeProgramString = std::get<std::string>(studentDataArray[8]);

        if (degreeProgramString == "SECURITY") {
            degreeProgram = SECURITY;
        } else if (degreeProgramString == "NETWORK") {
            degreeProgram = NETWORK;
        } else {
            degreeProgram = SOFTWARE;
        }
        
        add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram) {
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3, degreeProgram);
    /*
    S->setStudentID(studentID);
    S->setFirstName(firstName);
    S->setLastName(lastName);
    S->setEmail(email);
    S->setAge(age);
    S->setDegreeProgram(degreeProgram);
    S->setDaysToCompleteCourse(0, daysToCompleteCourse1);
    S->setDaysToCompleteCourse(1, daysToCompleteCourse2);
    S->setDaysToCompleteCourse(2, daysToCompleteCourse3);
     */
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        classRosterArray[i]->print();
    }
}
