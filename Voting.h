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

extern int numVotes;

struct Candidate
{
    string name;
    vector< vector<int> > votes;
    bool elim;

    Candidate():name(""), eliminated(false){}
};

bool tie (vector<Candidate>& cans);

bool winner (vector<Candidate>& cans);

void get_candidates (istream& r, int numNames, vector<Candidate>& cans);

void get_ballots (istream& r, vector<Candidate>& candidates);

void assign_ballot (vector<Candidate>& candidates, int column, vector<int> ballots);

void voting_solve (istream& r, ostream& w);

#endif // Voting_h


