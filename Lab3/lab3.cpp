#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "printWithComma.h"
#include "printScientific.h"
#include "printWithLetters.h"
#include "printClient.h"


using namespace std;

/******************************/
/* 1. Functions declarations  */
/******************************/


//Display the menu
void display_menu();


//Load at most max numbers from file numbers.txt
//into array X
//Return the number of values stored in X
int load_file(double *X, int max);



//Add any other needed functions


/******************************/
/* 2. Main function           */
/******************************/

int main()
{    
    const int MAX = 100;


    //printing strategies (algorithms)
    PrintWithComma pwc; //comma format
    PrintScientific psc;
    PrintWithLetters pwl;

     //a print client
    PrintClient printcon;


    int option = 3;
    double d = 0;

    double seq[MAX];
    int howMany = 0;

    do{
        
        display_menu();
        cout << "Option ? ";
        cin >> option;
        cin.ignore();

        cout << "\n\n";
        switch (option){
            case 1: cout << "The number: ";
                    cin >> d;
                    printcon.set_PrintStrategy(&pwc);
                    printcon.print(d);
                    break;
            case 2:
                    cout << "The number: ";
                    cin >> d;
                    printcon.set_PrintStrategy(&psc);
                    printcon.print(d);
                    break;
            case 3: 
                    cout << "The number: ";
                    cin >> d;
                    printcon.set_PrintStrategy(&pwl);
                    printcon.print(d);
                    break;
            case 4: 
                    howMany = load_file(seq, MAX);
                    printcon.set_PrintStrategy(&pwc);
                    printcon.print(seq, howMany, "Numbers with Comma Format");
                    break;
            case 5: 
                    howMany = load_file(seq, MAX);
                    printcon.set_PrintStrategy(&psc);
                    printcon.print(seq, howMany, "Numbers with Letter Format");
                    break;
            case 6: 
                    howMany = load_file(seq, MAX);
                    printcon.set_PrintStrategy(&pwl);
                    printcon.print(seq, howMany, "Numbers with Scientific Format");
                    break;
            case 7: break;
            default: cout << "Wrong option!!" << endl;
        }
   } while (option != 7);

   cout << endl << "GoodBye :)" << endl;

   return 0;
}

/******************************/
/* 3. Functions definitions   */
/******************************/

//Display the menu
void display_menu()
{
    cout << endl << setw(55) << setfill('*') << '*' << endl;
    cout << "1. Display with comma" << endl;
    cout << "2. Display with scientific notation" << endl;
    cout << "3. Display with letters" << endl;
    cout << "4. Generate comma format from file (numbers.txt)" <<endl;
    cout << "5. Generate scientific format from file (numbers.txt)" <<endl;
    cout << "6. Generate letters format from file (numbers.txt)" <<endl;
    cout << "7. Quit" << endl;
    cout << setw(55) << setfill('*') << '*' << endl;
    cout << setfill(' ');
}

//Load at most max numbers from file numbers.txt
//into array X
//Return the number of values stored in X
int load_file(double *X, int max)
{
    ifstream inFile("/Users/albert/Skola/TNG033/Lab3/numbers.txt");
        
    double tmp;
    int i = 0;
    
    while ( !inFile.eof() ) {
        //Make sure we got a number, and greater than 0
        if (inFile >> tmp) {
            X[i++] = tmp;
        }
        else{
            //Reset the stream and ignore the present value
            inFile.clear();
            inFile.ignore();
        }
    }  
    
    return i;
}


