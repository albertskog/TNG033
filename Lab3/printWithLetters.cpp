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
                cout << "zero ";
                break;
            case '1':
                cout << "one ";
                break;
            case '2':
                cout << "two ";
                break;
            case '3':
                cout << "three ";
                break;
            case '4':
                cout << "four ";
                break;
            case '5':
                cout << "five ";
                break;
            case '6':
                cout << "six ";
                break;
            case '7':
                cout << "seven ";
                break;
            case '8':
                cout << "eight ";
                break;
            case '9':
                cout << "nine ";
                break;
            case '.':
                cout << "comma ";
                break;
            case '-':
                cout << "minus ";
            default:
                break;
        }
    }
    
}