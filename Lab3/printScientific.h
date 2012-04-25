//
//  printScientific.h
//  Lab3
//
//  Created by Albert Skog on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Lab3_printScientific_h
#define Lab3_printScientific_h

#include "printStrategy.h"

class PrintScientific : public PrintStrategy{
public:
    void print(double d){std::cout << "scientific " << d;};
};

#endif
