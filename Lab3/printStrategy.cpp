//
//  printStrategy.cpp
//  Lab3
//
//  Created by Albert Skog on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include <iostream>
#include <sstream>
#include "printStrategy.h"

PrintStrategy::PrintStrategy(std::ostream& out){
    outputStream = out;
}
