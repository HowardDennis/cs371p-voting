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

    Candidate():name(""), elim(false){}
};

void eliminate_zero (vector<Candidate>& can, vector<Candidate>& losers);

void reassign (vector<Candidate>& candidates, int column, vector<Candidate>& losers);

void case_eval (istream& r, ostream& w);

bool eliminate (vector<Candidate>& can, vector<Candidate>& losers);

bool is_tie (vector<Candidate>& cans, ostream& w, vector<Candidate>& losers);

bool winner (vector<Candidate>& cans, ostream& w vector<Candidate>& losers);

void get_candidates (istream& r, int numNames, vector<Candidate>& cans);

void get_ballots (istream& r, vector<Candidate>& candidates, int numNames);

void assign_ballot (vector<Candidate>& candidates, int column, vector<int>& ballots);

void voting_solve (istream& r, ostream& w);

#endif // Voting_h


