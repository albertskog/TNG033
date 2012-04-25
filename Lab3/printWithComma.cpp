//
//  printWithComma.cpp
//  Lab3
//
//  Created by Albert Skog on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include "printWithComma.h"

using namespace std;

void PrintWithComma::print(double d){
    
    //convert to stringstream
    ostringstream tmp;
    tmp << d;
    
    string s = tmp.str();
    
    //remove trailing 0's
    while (*s.end() == '0') {
        s.erase(s.end());
    }
    
    //replace . with ,
    replace(s.begin(), s.end(), '.', ',');
    *PrintStrategy::outputStream << s;
    
    //add trailing ,0 if needed
    if (s.rfind(',') == s.npos) {
        *PrintStrategy::outputStream << ",0";
    }

}