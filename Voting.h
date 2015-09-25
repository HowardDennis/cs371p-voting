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

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

extern int numVotes;

bool winner (vector<int>& count, vector<string>& electees, vector<int>& losers, vector<string>& candidates, vector<int>& losers_total);
void print (ostream w, vector<string>& electees);
void elect (istream& r, ostream& w);
void run_cases (istream& r, ostream& w);
#endif // Voting_h


