
#include <sstream>
#include <iomanip>
#include "diver_info.h"

bool read_line(istream& in, double d[], double &dif);

//Implementera följande funktioner


//Funktionen läser data för diver, hopparen, j från strömmen in och
//returnerar strömmen. Först läses namnet som finns på en rad
//Then, call read_line to read the next line with the difficulty and the 7 scores
//If errors were encountered while reading the data of a diver j
//then j.difficulty is set to ERROR
//Det returneras strömmen in.
istream& read (istream& in, Diver_info& j)
{
    in.getline(j.name, NAME_LENGTH);
    
    if ( !read_line(in, j.points, j.difficulty) )
    {
        j.difficulty = ERROR;
    }

    return in;
}

//Function to read a line from in containing the difficulty and 7 scores
//The 7 scores should be stored in d and difficulty is stored in dif
//White spaces in the end of the line should be ignored
//If any errors in the line then return false
//Otherwise, return true
//Use stringstreams, see sec. 11.9 of course book and Fö 2
bool read_line(istream& in, double d[], double &dif)
{
    int scores = 0;
    double tmp;
    string line;
    getline(in, line);
    istringstream lstream(line);
        
    lstream >> dif;
    
    while ( (lstream >> tmp) && (scores < NR_OF_REF) )
    {
        d[scores++] = tmp;
    }
    
    //Skip whitespaces
    lstream >> ws;
    
    if (lstream.eof())
    {
        return true;
    }
    else
    {
        return false;
    }

}


//Beräknar totalpoäng för hoppet för diver j enligt reglerna, se instruktionen.
void calculate_final(Diver_info& j)
{
    double tmp = 0;
    
    sort(j.points, NR_OF_REF);
    
    for (int i = 1; i < NR_OF_REF-1; i++) {
        tmp += j.points[i];
    }
    
    j.final_score = ((double)3/(double)5 * j.difficulty * tmp);
}

void sort (double a[], int n)
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

//prints skriver ut data till standard output (cout) för diver j.
void print(const Diver_info& j)
{
    cout << setw(25) << left << j.name << setw(5) << j.final_score << endl;
}

