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

void voting_solve (istream& r, ostream& w) {
    int numCases;
    string s;
    getline(r, s);
    istringstream (s) >> numCases;
    assert(numCases > 0);
    getline(r, s); //skips line
    case_eval (r, w);
    numVotes = 0;
    --numCases;
    while(numCases > 0) {
        w << "\n";
        case_eval (r, w);
        numVotes = 0;
        --numCases;}
    }

void case_eval (istream& r, ostream& w) {
    string s;
    getline(r, s);
    int numNames;
    istringstream (s) >> numNames;
    assert(numNames >= 0 && numNames < 21);
    vector<Candidate> candidates;
    get_candidates(r, numNames, candidates);
    assert(candidates.size() == (unsigned)numNames);
    get_ballots(r, candidates, numNames);
    assert(numVotes <= 1000);
    vector<Candidate> losers;
    eliminate_zero(candidates, losers);
    bool win = winner(candidates, w);
    int i = 1;
    while(!win && i < numNames) {
        eliminate(candidates, losers);
        reassign(candidates, i, losers);
        win = winner(candidates, w);
        ++i;
    }
}

void reassign (vector<Candidate>& candidates, int column, vector<Candidate>& losers) {
    for (unsigned int i = 0; i < losers.size(); ++i) {
        for (unsigned int j = 0; j < losers[i].votes.size(); ++j) {
            if (!candidates[losers[i].votes[j][column]-1].elim) {
                assign_ballot(candidates, column, losers[i].votes[j]);
                losers[i].votes.erase(losers[i].votes.begin() + j);
            }
        }
    }
}

// --------
// Gets names from input and makes them into Candidate objects
// --------

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

void get_ballots (istream& r, vector<Candidate>& candidates, int numNames) {
    string s;
    while(getline(r, s) && !s.empty()) {
        stringstream stream(s);
        vector<int> temp;
        while(!stream.eof()) {
            int n;
            stream>>n;
            temp.push_back(n);
        }
        assert ((unsigned)numNames == temp.size());
        assign_ballot (candidates, 0, temp);
        ++numVotes;
    }
}

// --------
// assigns ballot to the candidate
// --------

void assign_ballot (vector<Candidate>& candidates, int column, vector<int>& ballot) {
    candidates[ballot[column] -1].votes.push_back(ballot);
}

// --------
// eliminates candidates
// --------

void eliminate (vector<Candidate>& can, vector<Candidate>& losers) {
    unsigned int min = 1001;
    for (unsigned int i = 0; i < can.size(); ++i) {
        if (!can[i].elim && min > can[i].votes.size() && can[i].votes.size() != 0) {
            min = can[i].votes.size();
        }
    }
    
    for (unsigned int i = 0; i < can.size(); ++i) {
        if (min == can[i].votes.size() || can[i].votes.size() == 0) {
            can[i].elim = true;
            losers.push_back(can[i]);
        }
    }
}

void eliminate_zero (vector<Candidate>& can, vector<Candidate>& losers) {
    for (unsigned int i = 0; i < can.size(); ++i) {
        if (can[i].votes.size() == 0) {
            can[i].elim = true;
            losers.push_back(can[i]);
        }
    }
}

// --------
// determines if there is a winner
// --------

bool winner (vector<Candidate>& cans, ostream& w) {
    for (unsigned int i = 0; i < cans.size(); ++i) {
        if (double(cans[i].votes.size()) > numVotes/2.0) {
            w << cans[i].name << endl;
            return true;
        }
    }
    return is_tie(cans, w);
}

bool is_tie (vector<Candidate>& cans, ostream& w) {
    unsigned int n;
    bool go = true;
    for (unsigned int i = 0; i < cans.size() && go; ++i) {
        if (!cans[i].elim) {
            n = cans[i].votes.size();
            go = false;
        }
    }
    for (unsigned int i = 1; i < cans.size(); ++i) {
        if (!cans[i].elim && n != cans[i].votes.size()) {
            return false;
        }
    }
    
    for (unsigned int i = 0; i < cans.size(); ++i) {
        if (!cans[i].elim) {
            w << cans[i].name << endl;
        }
    }
    
    return true;
}
