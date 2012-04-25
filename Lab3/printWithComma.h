//
//  printWithComma.h
//  Lab3
//
//  Created by Albert Skog on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Lab3_printWithComma_h
#define Lab3_printWithComma_h

#include "printStrategy.h"

class PrintWithComma : public PrintStrategy{
    public:
        void print(double d);
};

#endif
