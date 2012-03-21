#include <iostream>
#include <iomanip>
#include <ios>

#include "diver_info.h"

/******************************/
/* 1. Functions declarations  */
/******************************/


//print skriver data i n struct av typen Diver_info till cout
void print(const Diver_info j[], int n);

//sort sorterar array ju innehållande n struct av typen Diver_info på
//fältet result i fallande ordning.
void sort (Diver_info ju[], int n);

//swap byter värde på struct a och b. Används av funktionen sort.
void swap(Diver_info& a, Diver_info& b);


/******************************/
/* 2. Main function           */
/******************************/


const int NR_OF_DIVERS = 20;

int main ()
{
	Diver_info temp;
	Diver_info theDivers[NR_OF_DIVERS];

	int count = 0;

	while ( (count < NR_OF_DIVERS) && read(cin, temp) ) //if the stream has error bits set then it is converted to false
	{
		// if there are errors in the file for a diver then difficulty is set to ERROR
		if (temp.difficulty != ERROR)
            theDivers[count++] = temp;

    }
    
    for (int i = 0; i < count; i++ )
	{
		calculate_final (theDivers[i]); //calculate the final score for the diver
	}

	sort(theDivers, count);

	cout << "Resultatlista för simhoppning" << endl;
	print(theDivers, count);

	return 0;
}

/******************************/
/* 3. Functions definitions   */
/******************************/

//print skriver data i n struct av typen Diver_info till cout
void print(const Diver_info j[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << right << i+1 << ". ";
        print(j[i]);
    }
}

//sort sorterar array ju innehållande n struct av typen Diver_info på
//fältet result i fallande ordning.
void sort (Diver_info ju[], int n)
{
    int j;
    int minIndex;
    
    //Selection sort
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (ju[j].final_score > ju[minIndex].final_score)
            {
                minIndex = j;
            }
        }
        swap(ju[i], ju[minIndex]);
    }
}

//swap byter värde på struct a och b. Används av funktionen sort.
void swap(Diver_info& a, Diver_info& b)
{
    Diver_info temp = b;
    b = a;
    a = temp;
}


