//
//  printWithLetters.h
//  Lab3
//
//  Created by Albert Skog on 2012-05-02.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Lab3_printWithLetters_h
#define Lab3_printWithLetters_h

#include "printStrategy.h"

class PrintWithLetters : public PrintStrategy{
public:
    void print(std::ostream& outputStream, double d);
};

#endif
