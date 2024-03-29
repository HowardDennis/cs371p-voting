#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#include "Voting.h"

using namespace std;

bool check(int& v, vector<int>& losers_total) {
  bool bad = false;
  for (unsigned int i = 0; i < losers_total.size(); ++i) {
    if(losers_total[i] == (v - 1)) {
      bad = true;
      break;
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
    count[li] = 0;
  }
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
