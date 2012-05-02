//
//  printScientific.cpp
//  Lab3
//
//  Created by Albert Skog on 2012-04-26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "printScientific.h"

using namespace std;


void PrintScientific::print(std::ostream &outputStream, double d){
    
    ostringstream tmp;
    tmp << scientific << d;
    string s = tmp.str();
    int ePos = (int)s.find('e');

    
    //Get the coefficient, without trailing zeros
    int i = ePos;
    while (s.at(--i)=='0');    
    string coeff = s.substr(0, (s.at(i) == '.' ? i+2 : i+1));
    
    //replace . with ,
    replace(coeff.begin(), coeff.end(), '.', ',');
    
    outputStream << coeff << "*10^";
    
    //Now get the exponent
    
    //Print sign if -
    int exp = atoi(s.substr(ePos+1, s.npos).c_str());
    outputStream << exp;
    
}