//
//  ex3.cpp
//  dugga3-1
//
//  Created by Albert Skog
//  PNR:    870327-7593
//  LiU-id: albsk635
//
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//For the transform function
char to_lower(char c)
{
    return tolower(c);
}

//For sorting on line numbers
bool smaller(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

int main()
{
    typedef pair<string, int> word;
    typedef map<string, int> words;
    map<string, int>::iterator it;
    
    words Words;
    string tmp;
    
    //Get the words
    while ( cin >> tmp ) {

        //Transform word to lowercase
        transform(tmp.begin(), tmp.end(), tmp.begin(), to_lower);
            
        Words[tmp]++;
    }
    
    //Put unique words into a wordlist
    vector<word> wordlist;
    
    for (it = Words.begin(); it!=Words.end(); it++) {
        if (it->second != -1) {
            wordlist.push_back(*it);
        }
    }
    
    //Print header
    cout << setw(20) << left << "Word" << "Frequency\n\n";
    
    //Print in alphabetic order
    for (vector<word>::iterator jt = wordlist.begin(); jt != wordlist.end(); jt++) {
        cout << setw(20) << left << jt->first << jt->second << endl;
    }
    
    cout << "\n++++++++++++++++++++++++++++++\n\n";
    
    //Sort line numbers ascending and print again
    sort(wordlist.begin(), wordlist.end(), smaller);
    
    for (vector<word>::iterator jt = wordlist.begin(); jt != wordlist.end(); jt++) {
        cout << setw(20) << left << jt->first << jt->second << endl;
    }
    
    return 0;
    
}
