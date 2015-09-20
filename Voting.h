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

void voting_read_names (istream& r, int numNames, string names[]);

// ------------
// voting_eval
// ------------

int voting_eval (int i, int j);

// -------------
// voting_solve
// -------------

void voting_solve (istream& r, ostream& w);
#endif // Voting_h


