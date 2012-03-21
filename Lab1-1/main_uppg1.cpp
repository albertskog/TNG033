// Fil: ~\tng033\Laborationer\Lab1\Kod\main_uppg1.cpp
// Kenneth Bjerner 2003-12-21
// Ändrad 2005-01-21 av KB

#include <iostream>
#include "statistics.h"

#include <iostream>
#include "statistics.h"

//read_int läser heltal med cin >> till filslut, end of file, och lägger  
//in talen i arrayen a. Då man nått filslut ska strömmen återställas med 
//clear. Funktionen returnerar antalet inlästa heltal.
int read_int (int a[]);

//print skriver ut n heltal i arrayen a med cout. 10 tal per rad ska skrivas.
void print(int a[], int n);

//copy kopierar n heltal från arrayen from till arrayen to.
void copy (int *to, int *from, int n);

using std::cout;	using std::endl;

const int NR_OF_INTEGERS = 1000;

int main ()
{
	int theNumbers[NR_OF_INTEGERS], theCopy[NR_OF_INTEGERS];

	int count = read_int (theNumbers);
	copy (theCopy, theNumbers, count);
	sort(theCopy, count);
	cout << theNumbers [0] << " " << theNumbers [1] << endl;
	cout << "De inlästa talen osorterade" << endl;
	print(theNumbers, count);
	cout << "\nDe inlästa talen sorterade" << endl;
	print(theCopy, count);
	
	int max, min;
	max = maxmin(theNumbers, count, min);
	cout << "\nMax-värdet = " << max << " och min-värdet = " << min << endl;

	double theMean = mean(theNumbers, count);
	cout << "Medelvärdet = " << theMean << "." << endl;

	double m = median (theCopy, count);
	cout << "Medianvärdet = " << m << "." << endl;

	return 0;
}


//read_int läser heltal med cin >> till filslut, end of file, och lägger  
//in talen i arrayen a. Då man nått filslut ska strömmen återställas med 
//clear. Funktionen returnerar antalet inlästa heltal.
int read_int (int a[])
{
    int temp;
    int i = 0;
    while ( (i < NR_OF_INTEGERS) && (std::cin >> temp) ) {
        a[i++] = temp;
    }
    return i;
}

//print skriver ut n heltal i arrayen a med cout. 10 tal per rad ska skrivas.
void print(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << ( (n%11 == 10) ? "\n" : " " );
    }
}

//copy kopierar n heltal från arrayen from till arrayen to.
void copy (int *to, int *from, int n)
{
    for (int i = 0; i < n; i++) {
        to[i] = from[i];
    }
}
