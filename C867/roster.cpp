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
}

void Roster::remove(std::string id) {

    bool foundStudent = false;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && id == classRosterArray[i]->getStudentID()) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            foundStudent = true;
            break;
        }
    }
    if (foundStudent == false) {
        std::cout << "Error: Student " << id << " Not Found." << std::endl;
    }
    else if (foundStudent == true) {
        std::cout << "Student " << id << " removed." << std::endl;
    }
    return;
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] == nullptr)
            {
                continue;
            }
            else {
                classRosterArray[i]->print();
            }
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int average = (classRosterArray[i]->getDaysToCompleteCourse(0) + classRosterArray[i]->getDaysToCompleteCourse(1) + classRosterArray[i]->getDaysToCompleteCourse(2)) / 3;
            
            std::cout << "Average days in course: " << average << std::endl;
            }
        }
}

void Roster::printInvalidEmails() {
    // Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')
    for (int i = 0; i < 5; i++) {
        std::string email = classRosterArray[i]->getEmail();
        if (email.find('@') != std::string::npos &&
            email.find('.') != std::string::npos &&
            email.find(' ') == std::string::npos) {
                //std::cout << "String meets the criteria." << std::endl;
            } else {
                std::cout << "Invalid email: " << email << std::endl;
            }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; i++) {
        std::string degreeProgramString = degreeTypeStrings[degreeProgram];
        std::string studentDegreeProgram = degreeTypeStrings[classRosterArray[i]->getDegreeProgram()];
        if (studentDegreeProgram == degreeProgramString) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() {
    for (size_t i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
        }
    }
    return;
}
