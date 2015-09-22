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

string determine_winner (vector<Candidate>& cans) {
    for (int i = 0; i < cans.size(); ++i) {
        if (double(cans[i].votes.size()) > double(numVotes)/2.0) {
            return cans[i].name;
        }
    }
    return "";
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

void get_ballots2 (istream& r, vector<Candidate>& candidates) {
    string s;
    while(getline(r, s) && !s.empty()) {
        stringstream stream(s);
        vector<int> temp;
        while(stream) {
            int n;
            stream>>n;
            temp.push_back(n);
        }
        assign_ballot (candidates, 0, temp);
        ++numVotes;
    }
}

void assign_ballot (vector<Candidate>& candidates, int column, vector<int> ballot) {
    candidates[ballot[column] -1].votes.push_back(ballot);
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
        vector<Candidate> candidates;
        get_candidates(r, numNames, candidates);
        cout << candidates[0].name << endl;
        get_ballots2(r, candidates);
        cout << candidates[0].votes[0] << endl;
        string win = determine_winner(candidates);
        cout << winner.compare("") << endl;
        --numCases;}
    }


