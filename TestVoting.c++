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

// ----
// read
// ----

TEST(VotingFixture, read_names_1) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n");
    istringstream test_stream(s);
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    vector<string> names;
    voting_read_names(test_stream, numNames, names);
    ASSERT_EQ("John Doe", names[0]);
    ASSERT_EQ("Jane Smith", names[1]);
    ASSERT_EQ("Sirhan Sirhan", names[2]);
}

TEST(VotingFixture, read_names_2) {
    string s("3\nHannah Perry\nJane Smith\nSirhan Sirhan\n");
    istringstream test_stream(s);
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    vector<string> names;
    voting_read_names(test_stream, numNames, names);
    ASSERT_EQ("Hannah Perry", names[0]);
    ASSERT_EQ("Jane Smith", names[1]);
    ASSERT_EQ("Sirhan Sirhan", names[2]);
}

TEST(VotingFixture, get_ballots_1) {
    string s("1 2 3");
    istringstream test_stream(s);
    vector< vector<int> > ballots;
    get_ballots(test_stream, ballots);
    ASSERT_EQ(1, ballots[0][0]);
    ASSERT_EQ(2, ballots[0][1]);
    ASSERT_EQ(3, ballots[0][2]);
}

TEST(VotingFixture, get_ballots_2) {
    string s("1 2 3\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector< vector<int> > ballots;
    get_ballots(test_stream, ballots);
    ASSERT_EQ(1, ballots[0][0]);
    ASSERT_EQ(2, ballots[0][1]);
    ASSERT_EQ(3, ballots[0][2]);

    ASSERT_EQ(2, ballots[1][0]);
    ASSERT_EQ(1, ballots[1][1]);
    ASSERT_EQ(3, ballots[1][2]);

    ASSERT_EQ(3, ballots[2][0]);
    ASSERT_EQ(2, ballots[2][1]);
    ASSERT_EQ(1, ballots[2][2]);
}

TEST(VotingFixture, get_candidates_proper) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots2(test_stream, candidates);
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



TEST(VotingFixture, get_candidates_1) {
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
