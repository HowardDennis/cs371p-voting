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

<<<<<<< HEAD
extern int numVotes;

struct Candidate
{
    string name;
    vector< vector<int> > votes;
    bool elim;

    Candidate():name(""), elim(false){}
};

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void winner (vector<Candidate> can);
=======
bool winner (vector<Candidate>& cans);
>>>>>>> how
=======
=======
void eliminate_zero (vector<Candidate>& can, vector<Candidate>& losers);

>>>>>>> how
void reassign (vector<Candidate>& candidates, int column, vector<Candidate>& losers);
>>>>>>> how

void case_eval (istream& r, ostream& w);

bool eliminate (vector<Candidate>& can, vector<Candidate>& losers);

bool is_tie (vector<Candidate>& cans, ostream& w, vector<Candidate>& losers);

bool winner (vector<Candidate>& cans, ostream& w, vector<Candidate>& losers);

void get_candidates (istream& r, int numNames, vector<Candidate>& cans);

void get_ballots (istream& r, vector<Candidate>& candidates, int numNames);

void assign_ballot (vector<Candidate>& candidates, int column, vector<int>& ballots);

void voting_solve (istream& r, ostream& w);
=======
void reassign (vector<Candidate>& candidates, int column, vector<Candidate>& losers);

void case_eval (istream& r, ostream& w);

void eliminate (vector<Candidate>& can, vector<Candidate>& losers);

bool is_tie (vector<Candidate>& cans, ostream& w);

bool winner (vector<Candidate>& cans, ostream& w);

void get_candidates (istream& r, int numNames, vector<Candidate>& cans);

void get_ballots (istream& r, vector<Candidate>& candidates, int numNames);
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308
=======
void reassign(vector<int>& count, vector<int>& losers, vector<vector<string> >& ballots, vector<int>& losers_total);
bool check(int& v, vector<int>& losers_total);
bool winner(vector<int>& count, vector<string>& electees, vector<int>& losers, vector<string>& candidates, vector<int>& losers_total);
void sortVotes(istream& r, vector< vector<string> >& ballots, vector<int>& count, string& v);
void elect (istream& r, ostream& w);
void print(ostream& w, vector<string>&  winners);
void run_cases (istream& r, ostream& w);
#endif // Voting_h
>>>>>>> a20dfa4c3b563ae4bc24f840bd09213c1889aaa0

void assign_ballot (vector<Candidate>& candidates, int column, vector<int>& ballots);

void voting_solve (istream& r, ostream& w);

#endif // Voting_h