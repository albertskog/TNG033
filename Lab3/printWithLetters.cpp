//
//  printWithLetters.cpp
//  Lab3
//
//  Created by Albert Skog on 2012-05-02.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "printWithLetters.h"

using namespace std;

void PrintWithLetters::print(std::ostream &outStream, double d){
    //convert to stringstream
    ostringstream tmp;
    tmp << d;
    
    string s = tmp.str();
    
    //remove trailing 0's
    while (*s.end() == '0') {
        s.erase(s.end());
    }
    
    //add trailing ,0 if needed
    if (s.rfind('.') == s.npos) {
        s.append(".0");
    }
    
    for (size_t i = 0; i < s.length(); i++) {
        switch (s.at(i)) {
            case '0':
                outStream << "zero ";
                break;
            case '1':
                outStream << "one ";
                break;
            case '2':
                outStream << "two ";
                break;
            case '3':
                outStream << "three ";
                break;
            case '4':
                outStream << "four ";
                break;
            case '5':
                outStream << "five ";
                break;
            case '6':
                outStream << "six ";
                break;
            case '7':
                outStream << "seven ";
                break;
            case '8':
                outStream << "eight ";
                break;
            case '9':
                outStream << "nine ";
                break;
            case '.':
                outStream << "comma ";
                break;
            case '-':
                outStream << "minus ";
            default:
                break;
        }
    }
    
}