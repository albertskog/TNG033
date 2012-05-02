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
    int ePos = (int)tmp.str().find('e');
    string s = tmp.str();
    
    //Get the coeffivcient, without trailing zeros
    int i = ePos;
    while (s.at(--i)=='0');    
    string coeff = s.substr(0, (s.at(i) == '.' ? i+2 : i+1));
    
    //replace . with ,
    replace(coeff.begin(), coeff.end(), '.', ',');
    
    //Now get the exponent
    
    //Remove e, - (and leading 0's)
    int x = s.at(ePos+1) == '+' ? ePos+2 : ePos+1 ;
    string exp = s.substr(x, s.length());
    
    outputStream << coeff << "*10^" << exp;
}