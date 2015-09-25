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

void reassign(vector<int>& count, vector<int>& losers, vector<vector<string> >& ballots, vector<int>& losers_total);
bool check(int& v, vector<int>& losers_total);
bool winner(vector<int>& count, vector<string>& electees, vector<int>& losers, vector<string>& candidates, vector<int>& losers_total);
void sortVotes(istream& r, vector< vector<string> >& ballots, vector<int>& count, string& v);
void elect (istream& r, ostream& w);
void print(ostream& w, vector<string>&  winners);
void run_cases (istream& r, ostream& w);
#endif // Voting_h


