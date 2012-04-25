#include <iostream>
#include <string>

using namespace std;

/*******************************
* 1. function declarations     *
********************************/

//Add any needed declarations here



/*******************************
* 2. Main function             *
*******************************/

int main()
{

    //Add here the table definition
    //or any other code you need



    //DO NOT CHANGE THE CODE BELOW -- main()

    string name = "";
    string code = "";

    int option;

    do{
        cout << "1. Courses of a teacher" << endl;
        cout << "2. Teachers of a course" << endl;

        cout << "Option? ";
        cin >> option;
        cin.ignore();
        cout << endl;

        if (option == 1){

         cout << "Teacher name: ";
         getline(cin, name);
         courses_of_teacher(table, name);
         cout << endl;

         }
         else if (option == 2){

         cout << "Course code: ";
         getline(cin, code);
         teachers_of_course(table, code);
         cout << endl;


         }

    } while (option == 1 || option == 2); //exit with any option different from 1 or 2


    return 0;
}


/*******************************
* 3. Functions implementation  *
********************************/


//Add functions definitions here


