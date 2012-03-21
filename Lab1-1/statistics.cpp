// Fil: statistics.cpp
// 

#include <iostream>
#include <climits>
#include "statistics.h"

//Fyll på med kod för de olika funktionerna här

//Funktionen maxmin returnerar det största värdet bland n heltal i arrayen a. 
//Det minsta värdet i arrayen a placeras i referensparametern min.
int maxmin (int a[], int n, int& min)
{
    int max = a[0];
    min = a[0];
    
    for (int i = 1; i < n; i++) {
        if ( min > a[i] ) {
            min = a[i];
        }
        else if ( max < a[i] ) {
            max = a[i];
        }
    }
    return max;
}

//Funktionen mean beräknar medelvärdet för n heltal i arrayen a.
//Medelvärdet returneras från funktionen.
double mean (int a[], int n)
{
    double sum  = 0;
    
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum/n;
}

//Funktionen median beräknar medianvärdet för n heltal i den sorterade 
//arrayen a och returnerar detta värde. Medianvärdet är det mittersta värdet  
//i den sorterade arrayen. Om n är jämnt blir det medelvärdet av de två talen
//i mitten.
double median (int a[], int n)
{
    return n%2 ? (double) a[n/2-1] : ((double) (a[n/2-1] + a[n/2]) / 2);
}

//Funktionen sort sorterar n heltal i arrayen a med en annan sorterings-
//algoritm än bubblesort.
void sort (int a[], int n)
{
    int j;
    int minIndex;
    
    //Selection sort
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

//swap byter värde på de formella parametrarna a och b och används av sort
void swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}