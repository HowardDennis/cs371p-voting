#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#include "Voting.h"

using namespace std;

<<<<<<< HEAD
int numVotes = 0;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void winner (vector<Candidate> can) {
    
=======
// --------
// determines if there is a winner
// --------
=======
=======
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308
void voting_solve (istream& r, ostream& w) {
    int numCases;
    string s;
    getline(r, s);
    istringstream (s) >> numCases;
    assert(numCases > 0);
    getline(r, s); //skips line
    w << 101 - numCases << endl;
    case_eval (r, w);
    numVotes = 0;
    --numCases;
    while(numCases > 0) {
        w << "\n";
        w << 101 - numCases << endl;
        case_eval (r, w);
        numVotes = 0;
        --numCases;}
    }
<<<<<<< HEAD
>>>>>>> how
=======
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308

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
    bool win = winner(candidates, w, losers);
    int i = 1;
    while(!win && i < numNames) {
        bool b = true;
        int j = 0;
        while (b && !win && j < numNames) {
            b = eliminate(candidates, losers);
            reassign(candidates, i, losers);
            win = winner(candidates, w, losers);
            ++j;
        }
        ++i;
=======
bool check(int& v, vector<int>& losers_total) {
  bool bad = false;
  for (unsigned int i = 0; i < losers_total.size(); ++i) {
    if(losers_total[i] == (v - 1)) {
      bad = true;
      break;
>>>>>>> a20dfa4c3b563ae4bc24f840bd09213c1889aaa0
    }
  }
  return bad;
}

void reassign(vector<int>& count, vector<int>& losers, vector<vector<string> >& ballots, vector<int>& losers_total) { 
  int li, v;
  bool bad;
  string remaining_vote;
  for(unsigned int i = 0; i < losers.size(); ++i) {
    li = losers[i];
    for(unsigned int j = 0; j < ballots[li].size(); ++j) {
      stringstream a (ballots[li][j]);
      a >> v;
      bad = check(v, losers_total);
      while(bad) {
        a >> v;
        bad = check(v, losers_total);
      }
      getline(a, remaining_vote);
      ++count[v - 1];
      ballots[v - 1].push_back(remaining_vote);
    }
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    return false;
>>>>>>> how
=======
>>>>>>> how
=======
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308
=======
    count[li] = 0;
  }
>>>>>>> a20dfa4c3b563ae4bc24f840bd09213c1889aaa0
}

bool winner(vector<int>& count, vector<string>& electees, vector<int>& losers, vector<string>& candidates, vector<int>& losers_total) {
  int min = 1000, max = 0, t = 0;
  bool no_win = true;
  electees.clear();
  losers.clear();
  for(unsigned int i = 0; i < count.size(); ++i) {
    t += count[i];
    if(count[i] > max) {
      max = count[i];}
    if(count[i] < min && count[i] > 0) {
      min = count[i];}
  }
  
  if(max == min) {
    no_win = false;}

  for(unsigned int i = 0; i < count.size(); ++i) {
    if(count[i] > (t / 2)) {
      no_win = false;
      electees.push_back(candidates[i]);}
    else if(count[i] == max) {
      electees.push_back(candidates[i]);}
    if(count[i] == min) {
      losers.push_back(i);
      losers_total.push_back(i);}
  }
  return no_win;
}

void sortVotes(istream& r, vector< vector<string> >& ballots, vector<int>& count, string& v) {
  char c = r.peek();
  if(c == EOF || c == '\n' || !r) {
   return;}

  unsigned a;
  r >> a;
  assert(a > 0);
  
  for(unsigned int i = a-1; i < a; ++i) {
    ++count[i];
  }
  if(a > 1) {
  r.ignore(1);}
  getline(r, v);
  for(unsigned int j = a-1; j < a; ++j) {
    ballots[j].push_back(v);
  }
    sortVotes(r, ballots, count, v);
}

void print(ostream& w, vector<string>&  electees) {
  assert(!electees.empty());
  for(unsigned int i = 0; i < electees.size(); ++i) {
    w << electees[i];
    w << "\n";
  }
}

<<<<<<< HEAD
// --------
// eliminates candidates
// --------

bool eliminate (vector<Candidate>& can, vector<Candidate>& losers) {
    unsigned int min = 1001;
    unsigned int max = 0;
    bool ret = false;
    for (unsigned int i = 0; i < can.size(); ++i) {
        if (!can[i].elim && min > can[i].votes.size() && can[i].votes.size() != 0) {
            min = can[i].votes.size();
        }
        if (!can[i].elim && max < can[i].votes.size() && can[i].votes.size() != 0) {
            max = can[i].votes.size();
        }
    }
    
    for (unsigned int i = 0; i < can.size(); ++i) {
        if ((min == can[i].votes.size() || can[i].votes.size() == 0) && can[i].votes.size() != max) {
            can[i].elim = true;
            losers.push_back(can[i]);
            ret = true;
        }
    }
    return ret;
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

bool winner (vector<Candidate>& cans, ostream& w, vector<Candidate>& losers) {
    for (unsigned int i = 0; i < cans.size(); ++i) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
        if (!cans[i].elim) {
            w << cans[i].name << " " << cans[i].votes.size() << endl;
        }
    }
    for (unsigned int i = 0; i < cans.size(); ++i) {
        
        if (double(cans[i].votes.size()) > numVotes/2.0) {
=======
=======
        if (!cans[i].elim) {
            w << cans[i].name << cans[i].votes.size() << endl;
        }
    }
    
    for (unsigned int i = 0; i < cans.size(); ++i) {
>>>>>>> how
        if (!cans[i].elim && double(cans[i].votes.size()) > numVotes/2.0) {
>>>>>>> how
            w << cans[i].name << endl;
            return true;
        }
=======
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
>>>>>>> a20dfa4c3b563ae4bc24f840bd09213c1889aaa0
    }
    vector< vector<string> > ballots(numNames + 20);
    string v;
    sortVotes(r, ballots, count, v);
    vector<string> electees;
    vector<int> losers, losers_total;
    bool no_win = winner(count, electees, losers, candidates, losers_total);
    while(no_win) {
    reassign(count, losers, ballots, losers_total);
    no_win = winner(count, electees, losers, candidates, losers_total);
  }
  print(w, electees);

  ballots.clear();
  count.clear();
  candidates.clear();
  losers_total.clear();
  losers.clear();
  electees.clear();
}

void run_cases(istream& r, ostream& w) {
  int cases;
  r >> cases;
  assert(cases > 0);
  r.ignore();
  for(int y = 0; y < cases; ++y) {
    r.ignore();
    elect(r, cout);
    if(y < cases - 1){w << '\n';}
  }
}
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308
