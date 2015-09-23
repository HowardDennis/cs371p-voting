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

int numVotes = 0;

// --------
// determines if there is a winner
// --------

bool winner (vector<Candidate>& cans) {
    for (unsigned int i = 0; i < cans.size(); ++i) {
        if (double(cans[i].votes.size()) > numVotes/2.0) {
            cout << cans[i].name << endl;
            return true;
        }
    }
    return false;
}

void get_candidates (istream& r, int numNames, vector<Candidate>& cans) {
    int i = 0;
    string s;
    while(numNames > i) {
        getline(r, s);
        Candidate can;
        can.name = s;
        cans.push_back(can);
        ++i;
    }
}

// --------
// makes the string of numbers into vectors
// --------

void get_ballots (istream& r, vector<Candidate>& candidates) {
    string s;
    while(getline(r, s) && !s.empty()) {
        stringstream stream(s);
        vector<int> temp;
        while(!stream.eof()) {
            int n;
            stream>>n;
            temp.push_back(n);
        }
        assign_ballot (candidates, 0, temp);
        ++numVotes;
    }
}

// --------
// assigns ballot to the candidate
// --------

void assign_ballot (vector<Candidate>& candidates, int column, vector<int> ballot) {
    candidates[ballot[column] -1].votes.push_back(ballot);
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
        vector<Candidate> candidates;
        get_candidates(r, numNames, candidates);
        get_ballots(r, candidates);
        bool win = winner(candidates);
        cout << win << endl;
        --numCases;}
    }
