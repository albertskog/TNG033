#include <string>
#include <iostream>
#include <iomanip>

#include "printWithComma.h"
#include "printScientific.h"
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

     //a print client
    PrintClient printcon;


    int option;
    double d = 0;

    double seq[MAX];
    int howMany = 0;

    do{
        display_menu();
        cout << "Option ? ";
        cin >> option;
        cin.ignore();

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
            case 3: //Add code
                    break;
            case 4: //Add code
                    break;
            case 5: //Add code
                    break;
            case 6: //Add code
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
    //Add code
    return 0;
}


