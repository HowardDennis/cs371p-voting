// ----------------------------
// projects/voting/Voting.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Voting.h"

using namespace std;

// ------------
// voting_read
// ------------

pair<int, int> voting_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// Read the names for a case
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
// voting_print
// -------------

void voting_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

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


