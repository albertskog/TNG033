//
//  printClient.cpp
//  Lab3
//
//  Created by Albert Skog on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "printClient.h"
using namespace std;

PrintClient::~PrintClient(){

}

//Sets the print strategy to the one given by newPrintStrategy
void PrintClient::set_PrintStrategy (PrintStrategy *newPrintStrategy){
    currentPrintStrategy = newPrintStrategy;
}

void PrintClient::print(double x){
    currentPrintStrategy->print(currentOutStream, x);
}

void PrintClient::print(double *X, int n, std::string header){    
    ofstream outFile("out.txt");
    
    outFile << header << endl;

    for (int i = 0; i < n; i++) {
        currentPrintStrategy->print(outFile, X[i]);
        outFile << endl;
    }
    
    outFile.close();
}