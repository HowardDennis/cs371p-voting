// --------------------------------
// projects/voting/TestVoting.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <vector>   // vector

#include "gtest/gtest.h"

#include "Voting.h"

using namespace std;

// -----------
// TestVoting
// -----------

TEST(VotingFixture, get_candidates_1) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ASSERT_EQ(1, candidates[0].votes[0][0]);
    ASSERT_EQ(2, candidates[0].votes[0][1]);
    ASSERT_EQ(3, candidates[0].votes[0][2]);
    ASSERT_EQ(2, candidates[1].votes[0][0]);
    ASSERT_EQ(1, candidates[1].votes[0][1]);
    ASSERT_EQ(3, candidates[1].votes[0][2]);
    ASSERT_EQ(3, candidates[2].votes[0][0]);
    ASSERT_EQ(2, candidates[2].votes[0][1]);
    ASSERT_EQ(1, candidates[2].votes[0][2]);
}



TEST(VotingFixture, get_candidates_2) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n");
    istringstream test_stream(s);
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    vector<Candidate> cans;
    get_candidates(test_stream, numNames, cans);
    ASSERT_EQ("John Doe", cans[0].name);
    ASSERT_EQ("Jane Smith", cans[1].name);
    ASSERT_EQ("Sirhan Sirhan", cans[2].name);
}

TEST(VotingFixture, assign_ballot_1) {
    Candidate can_1;
    Candidate can_2;
    Candidate can_3;
    vector<Candidate> candidates = {can_1, can_2, can_3};
    vector<int> ballot_1 = {3, 1, 2};
    assign_ballot(candidates, 0, ballot_1);
    ASSERT_EQ(candidates[2].votes[0][0], 3);
    ASSERT_EQ(candidates[2].votes[0][1], 1);
    ASSERT_EQ(candidates[2].votes[0][2], 2);
    vector<int> ballot_2 = {2, 3, 1};
    assign_ballot(candidates, 1, ballot_2);
    ASSERT_EQ(candidates[2].votes[1][0], 2);
    ASSERT_EQ(candidates[2].votes[1][1], 3);
    ASSERT_EQ(candidates[2].votes[1][2], 1);
}

TEST(VotingFixture, winner_1) {
    Candidate can_1;
    can_1.name = "John Doe";
    Candidate can_2;
    can_2.name = "Jane Smith";
    Candidate can_3;
    can_3.name = "Sihran Sihran";
    vector<Candidate> candidates = {can_1, can_2, can_3};
    vector<int> ballot_1 = {3, 1, 2};
    vector<int> ballot_2 = {3, 2, 1};
    vector<int> ballot_3 = {1, 2, 3};
    vector<int> ballot_4 = {3, 1, 2};
    assign_ballot(candidates, 0, ballot_1);
    assign_ballot(candidates, 0, ballot_2);
    assign_ballot(candidates, 0, ballot_3);
    assign_ballot(candidates, 0, ballot_4);
    ostringstream w;
    ASSERT_TRUE(winner(candidates, w));
}

TEST(VotingFixture, winner_2) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ostringstream w;
    ASSERT_FALSE(winner(candidates, w));
}

TEST(VotingFixture, is_tie_1) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ostringstream w;
    bool c = is_tie(candidates, w);
    ASSERT_TRUE(c);
}

TEST(VotingFixture, is_tie_2) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n2 3 1\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ostringstream w;
    bool c = is_tie(candidates, w);
    ASSERT_FALSE(c);
}

TEST(VotingFixture, is_tie_3) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ostringstream w;
    bool c = is_tie(candidates, w);
    ASSERT_TRUE(c);
}

TEST(VotingFixture, eliminate_1) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n2 3 1\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    vector<Candidate> losers;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    bool b = eliminate(candidates, losers);
    ASSERT_TRUE(candidates[0].elim);
    ASSERT_FALSE(candidates[1].elim);
    ASSERT_FALSE(candidates[2].elim);
}
