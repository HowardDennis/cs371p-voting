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
#include <vector>   // vector

#include "Voting.h"

using namespace std;

void get_candidates (istream& r, int numNames, vector<Candidate>& cans) {
    
}

// Read the names for a case
void voting_read_names (istream& r, int numNames, vector<string>& names) {
    int i = 0;
    string s;
    while(numNames > i) {
        getline(r, s);
        names.push_back(s);
        ++i;
    }
}

// ------------
// voting_eval
// ------------


void get_ballots (istream& r, vector< vector<int> >& ballots) {
    string s;
    while(getline(r, s) && !s.empty()) {
        stringstream stream(s);
        vector<int> temp;
        while(stream) {
            int n;
            stream>>n;
            temp.push_back(n);
        }
        ballots.push_back(temp);
    }
}

void count_votes (vector< vector<int> >& ballots, vector< vector<int> >& votes, int column) {
    
}

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

        // Names on the ballot
        vector<string> names;
        voting_read_names(r, numNames, names);
        vector< vector<int> > votes;

        // All of the ballot rankings.
        vector< vector<int> > ballots;
        get_ballots(r, ballots);
        for (int i = 0; i < numNames; i++) {
            vector<int> temp;
            votes.push_back(temp);
        }

        --numCases;}
    }


