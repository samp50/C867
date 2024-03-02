//
//  main.cpp
//  C867
//
//  Created by Samuel Phillips on 2/22/24.
//

#include <iostream>
#include "student.hpp"
#include "roster.hpp"
#pragma once

int main(int argc, const char * argv[]) {
    const std::string studentData[] = {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Samuel,Phillips,sphi512@wgu.edu,24,8,10,15,SOFTWARE"};
    
    std::cout <<"C867-Scripting & Programming: Applications"<< std::endl;
    std::cout << "Language: C++ " << std::endl;
    std::cout << "Student ID: 011222682" << std::endl;
    std::cout << "Name: Samuel Phillips" << std::endl;
    std::cout << "   " << std::endl;
    std::cout << "   " << std::endl;
    
    Roster classRoster;
    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }
    
    classRoster.printAll();

    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; ++i) {
        
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");
}
