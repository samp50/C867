//
//  student.hpp
//  C867
//
//  Created by Samuel Phillips on 2/22/24.
//

#ifndef student_hpp
#define student_hpp
#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include "degree.hpp"

class Student {
    private:
        std::string StudentID, FirstName, LastName, Email;
        int Age;
        int DaysToCompleteCourse [3];
        enum DegreeProgram DegreeProgram;
        
    public:
        //static const std::string degreeTypeStrings[]; // delete?
        Student(const std::string& studentID, const std::string& firstName, const std::string& lastName,
                const std::string& email, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, enum DegreeProgram degreeProgram)
                : StudentID(studentID), FirstName(firstName), LastName(lastName),
        Email(email), Age(age), DegreeProgram(degreeProgram) {
            this->DaysToCompleteCourse[0] = daysToCompleteCourse1;
            this->DaysToCompleteCourse[1] = daysToCompleteCourse2;
            this->DaysToCompleteCourse[2] = daysToCompleteCourse3;
        }
        
        std::string getStudentID() const {
            return StudentID;
        }
        
        std::string getFirstName() const {
            return FirstName;
        }
        
        std::string getLastName() const {
            return LastName;
        }
        
        std::string getEmail() const {
            return Email;
        }
        
        int getAge() const {
            return Age;
        }
        
        int getDaysToCompleteCourse(int index) const {
            return DaysToCompleteCourse[index];
        }
        
        enum DegreeProgram getDegreeProgram() const {
            return DegreeProgram;
        }
        
        void setStudentID(std::string StudentID) {
            StudentID = StudentID;
        }
        
        void setFirstName(std::string FirstName) {
            FirstName = FirstName;
        }
        
        void setLastName(std::string LastName) {
            LastName = LastName;
        }
        
        void setEmail(std::string Email) {
            Email = Email;
        }
        
        void setAge(int age) {
            age = age;
        }
        
        void setDaysToCompleteCourse(int index, int value) {
            DaysToCompleteCourse[index] = value;
        }
        
        void setDegreeProgram(enum DegreeProgram DegreeProgram) {
            DegreeProgram = DegreeProgram;
        }
        
        void print() {
            std::cout << getStudentID() << '\t';
            std::cout << "First name: " << getFirstName() << '\t';
            std::cout << "Last name: " << getLastName() << '\t';
            //std::cout << getEmail() << '\t';
            std::cout << "Age: " << getAge() << '\t';
            std::cout << "Course length: {" << getDaysToCompleteCourse(0) << ", " << getDaysToCompleteCourse(1) << ", " << getDaysToCompleteCourse(2) << "}" << '\t';
            std::cout << "Degree program: " << degreeTypeStrings[getDegreeProgram()] << '\n';
        };
    };



#endif /* student_hpp */
