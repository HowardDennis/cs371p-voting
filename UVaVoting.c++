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
    bool elim;

    Candidate():name(""), elim(false){}
};

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
// assigns ballot to the candidate
// --------

void assign_ballot (vector<Candidate>& candidates, int column, vector<int>& ballot) {
    candidates[ballot[column] -1].votes.push_back(ballot);
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
// eliminates candidates
// --------

void eliminate (vector<Candidate>& can, vector<Candidate>& losers) {
    unsigned int min = 1001;
    for (unsigned int i = 0; i < can.size(); ++i) {
        if (!can[i].elim && min > can[i].votes.size()) {
            min = can[i].votes.size();
        }
    }
    
    for (unsigned int i = 0; i < can.size(); ++i) {
        if (min == can[i].votes.size()) {
            can[i].elim = true;
            losers.push_back(can[i]);
        }
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
// determines if there is a winner
// --------

bool winner (vector<Candidate>& cans, ostream& w) {
    for (unsigned int i = 0; i < cans.size(); ++i) {
        if (double(cans[i].votes.size()) > numVotes/2.0) {
            w << cans[i].name << endl;
            return true;
        }
    }
    return false;
}

bool is_tie (vector<Candidate>& cans, ostream& w) {
    unsigned int n = cans[0].votes.size();
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
    bool win = winner(candidates, w);
    bool draw = is_tie(candidates, w);
    vector<Candidate> losers;
    int i = 1;
    while(!win && !draw && i < numNames) {
        eliminate(candidates, losers);
        reassign(candidates, i, losers);
        win = winner(candidates, w);
        draw = is_tie(candidates, w);
        ++i;
    }
}

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

int main () {
    using namespace std;
    voting_solve(cin, cout);
    return 0;}