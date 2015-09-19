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
string* voting_read_names (istream& r) {
    string s;
    int numNames;
    getline(r, s);
    istringstream (s) >> numNames;
    string names[numNames];
    int i = 0;
    while(numNames > i) {
        getline(r, names[i]);
        ++i;
    }
    return names;
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
    string s;
    getline(r, s);
    istringstream (s) >> numCases;
    getline(r, s);
    string* names;
    while(numCases > 0) {
        names = voting_read_names(r);
        --numCases;}
        
    }


