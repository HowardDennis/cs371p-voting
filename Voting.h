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
#include <vector>

using namespace std;

struct Candidate
{
    string name;
    vector< vector<int> > votes;
    bool eliminated;

    Candidate():name(""), eliminated(false){}
};

void get_candidates (istream& r, int numNames, vector<Candidates>& cand) {
    int i = 0;
    string s;
    while(numNames > i) {
        getline(r, s);
        Candidate can;
        can.name = s;
        cand.push_back(can);
        ++i;
    }
}
void voting_read_names (istream& r, int numNames, vector<string>& names);

// ------------
// voting_eval
// ------------

void get_ballots (istream& r, vector< vector<int> >& ballots);

void count_votes (vector< vector<int> >& ballots, vector< vector<int> >& votes, int column);

// -------------
// voting_solve
// -------------

void voting_solve (istream& r, ostream& w);
#endif // Voting_h


