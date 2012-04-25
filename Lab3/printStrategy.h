//
//  printStrategy.h
//  Lab3
//
//  Created by Albert Skog on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Lab3_printStrategy_h
#define Lab3_printStrategy_h

#include <iostream>
#include <sstream>

class PrintStrategy{
    public:
    PrintStrategy(std::ostream& out = std::cout);
        virtual void print(double d) = 0;
    protected:
        std::ostream& outputStream;
};

#endif
