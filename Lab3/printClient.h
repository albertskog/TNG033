#ifndef PRINTCLIENT_H_INCLUDED
#define PRINTCLIENT_H_INCLUDED

#include <iostream>
#include <string>

#include "printStrategy.h"

//using namespace std;


class PrintClient {
    public:
        //constructor that creates a print client that prints with
        //a print strategy given by newPrintStrategy
        //and prints to the output stream out
    PrintClient(std::ostream& out = std::cout, PrintStrategy *newPrintStrategy = NULL): currentOutStream(out), currentPrintStrategy(newPrintStrategy) {};

    ~PrintClient();

        //Sets the print strategy to the one given by newPrintStrategy
    void set_PrintStrategy(PrintStrategy *newPrintStrategy);

        //Prints a double d with the strategy set for the print client
        //Prints to the output stream set for the client
    void print(double x);

        //Prints an array X of n doubles
        //with te strategy set for the print client
        //Prints to the output stream set for the client
        //A header is printed first
    void print(double *X, int n, std::string header = "");


    private:
        //Add any needed data members here
        PrintStrategy *currentPrintStrategy;
        std::ostream& currentOutStream;
};


#endif //PRINTCLIENT_H_INCLUDED


