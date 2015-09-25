#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#include "Voting.h"

using namespace std;

int numVotes = 0;

void check (int& v, vector<int>& losers_total) {
    bool yes = false;
    for (unsigned int i = 0, i < losers_total.size(); ++i) {
        if (losers_total[i] == (v - 1)) {
            yes = true;
            break;
        }
    }
    return yes;
}
void reassign (vector<int>& count, vector<int>& losers, vector<vector<int> >& ballots, vector<int>& losers_total) {
    int li;
    bool bad;
    for (unsigned int i = 0; i < losers.size(); ++i) {
        li = losers[i];
        for (unsigned int j = 0; j < ballots[li].size(); ++j) {
            bad = check (ballots[li][j], losers_total);
            
            while (bad) {
                bad = check (ballots[li][j], losers_total)
            }
        }
    }
}
bool winner (vector<int>& count, vector<string>& electees, vector<int>& losers, vector<string>& candidates, vector<int>& losers_total) {
    bool no_winner = true;
    int min = 1001, max = 0;
    electees.clear();
    losers.clear();
    for (unsigned int i = 0; i < count.size(); ++i) {
        if (count[i] > max) {
            max = count[i];
        }
        if (count[i] < min && count[i] > 0) {
            min = count[i];
        }
    }
    
    if(max == min) {
        no_winner = false;
    }
    
    for (unsigned int i = 0; i < count.size(); ++i) {
        if (count[i] > (numVotes / 2)) {
            no_winner = false;
            electees.push_back(candidates[i]);
        }
        else if (count[i] == max) {
            electees.push_back(candidates[i]);
        }
        if (count[i] == min) {
            losers.push_back(i);
            losers_total.push_back(i);
        }
    }
    return no_winner;
}
void print (ostream w, vector<string>& electees) {
    for (unsigned int i = 0; i < electees.size(); ++i) {
        w << electees[i];
        endl(w);
    }
}
void elect (istream& r, ostream& w) {
    string s;
    getline(r, s);
    int numNames;
    istringstream (s) >> numNames;
    assert(numNames >= 0 && numNames < 21);
    vector<string> candidates(numNames);
    vector<int> count(numNames, 0);
    int i = 0;
    while(numNames > i) {
        getline(r, s);
        candidates[i] = s;
        ++i;
    }
    vector< vector<int> > ballots;
    while(getline(r, s) && !s.empty()) {
        stringstream stream(s);
        vector<int> temp;
        while(!stream.eof()) {
            int n;
            stream>>n;
            ++count[n - 1];
            ++numVotes;
            temp.push_back(n);
        }
        ballots.push_back(temp);
    }
    vector<string> electees;
    vector<int> losers, losers_total;
    bool no_win = winner(count, electees, losers, candidates, losers_total);
    while (no_win) {
        reassign (count, electees, ballots, losers_total);
    }
}

void run_cases (istream& r, ostream& w) {
    int cases;
    string s;
    getline(r, s);
    istringstream (s) >> cases;
    assert(cases > 0);
    getline(r, s); //skips line
    elect (r, w);
    numVotes = 0;
    --cases;
    while(cases > 0) {
        w << "\n";
        elect (r, w);
        numVotes = 0;
        --cases;
    }
}
