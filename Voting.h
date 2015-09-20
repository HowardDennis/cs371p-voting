// --------------------------
// projects/voting/Voting.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Voting_h
#define Voting_h

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string

using namespace std;

void voting_read_names (istream& r, int numNames, string names[]) {
    int i = 0;
    while(numNames > i) {
        getline(r, names[i]);
        ++i;
    }
}

// ------------
// voting_eval
// ------------

int voting_eval (int i, int j) {
    // <your code>
    return 1;}

// -------------
// voting_solve
// -------------

void voting_solve (istream& r, ostream& w) {
    int numCases;
    int numNames;
    string s;
    getline(r, s);
    istringstream (s) >> numCases;
    getline(r, s);
    while(numCases > 0) {
        getline(r, s);
        istringstream (s) >> numNames;
        string names[numNames];
        voting_read_names(r, numNames, names);
        --numCases;}
        
    }
#endif // Voting_h


