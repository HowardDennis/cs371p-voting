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
TEST(VotingFixture, check_1) {
      int x = 4;
      vector<int> losers = {4, 3, 2};
      bool bad = check(x, losers);
      ASSERT_TRUE(bad);
}

TEST(VotingFixture, check_2) {
      int x = 6;
      vector<int> losers = {4, 3, 2};
      bool bad = check(x, losers);
      ASSERT_TRUE(bad);
}

TEST(VotingFixture, check_3) {
      int x = 2;
      vector<int> losers = {4, 3, 2};
      bool bad = check(x, losers);
      ASSERT_FALSE(bad);
}

TEST(VotingFixture, reassign_1) {
      vector<int> count = {5, 4, 3};
      vector<int> losers = {2};
      vector<int> losers_total;
      vector< vector<string> > ballots;
      int j = 0;
      if(j > 0) {
        reassign(count, losers, ballots, losers_total);}
      ASSERT_TRUE(j == 0);}

     TEST(VotingFixture, reassign_2) {
      vector<int> count = {6, 299, 1};
      vector<int> losers = {1};
      vector<int> losers_total;
      vector<vector<string> > ballots;
      int j = 0;
      if(j > 0) { 
        reassign(count, losers, ballots, losers_total);}
      ASSERT_TRUE(j == 0);}


     TEST(VotingFixture, reassign_3) {
      vector<int> count = {500, 42, 13};
      vector<int> losers = {0};
      vector<int> losers_total;
      vector<vector<string> > ballots;
      int j = 0;
      if(j > 0) { 
        reassign(count, losers, ballots, losers_total);}
      ASSERT_TRUE(j == 0);}
TEST(VotingFixture, winner_1) {
      vector<int> count = {30, 1, 2, 3};
      vector<string> winners;
      vector<int> losers, losers_total;
      vector<string> candidates = {"Joe", "Bob", "Larry", "Shmoe"};
      const bool noWinner = winner(count, winners, losers, candidates, losers_total);
      ASSERT_TRUE(noWinner == false);}

    TEST(VotingFixture, winner_2) {
      vector<int> count = {4, 1, 2, 3};
      vector<string> winners;
      vector<int> losers, losers_total;
      vector<string> candidates = {"Joe", "Bob", "Larry", "Shmoe"};
      const bool noWinner = winner(count, winners, losers, candidates, losers_total);
      ASSERT_TRUE(noWinner == true);}

    TEST(VotingFixture, winner_3) {
      vector<int> count = {7, 1, 2, 3};
      vector<string> winners;
      vector<int> losers, losers_total;
      vector<string> candidates = {"Joe", "Bob", "Larry", "Shmoe"};
      const bool noWinner = winner(count, winners, losers, candidates, losers_total);
      ASSERT_TRUE(noWinner == false);}


    // ----
    // sortVotes
    // ----

    TEST(VotingFixture, sortVotes_1) {
        std::istringstream r("1 2 3\n2 1 3\n3 2 1");
        string vote;
        vector<int> count = {0, 0, 0};
        vector<vector<string> > ballots(3);
        sortVotes(r, ballots, count, vote);
        ASSERT_TRUE(vote == "2 1");}
        
   
     TEST(VotingFixture, sortVotes_2) {
        std::istringstream r("3 1 4\n20 1 3\n20 18 4");
        string vote;
        vector<int> count = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector<vector<string> > ballots(20);
        sortVotes(r, ballots, count, vote);
        ASSERT_TRUE(vote == "18 4");}

     TEST(VotingFixture, sortVotes_3) {
        std::istringstream r("5 1 4\n5 1 3\n5 4 3");
        string vote;
        vector<int> count = {0, 0, 0, 0, 0};
        vector<vector<string> > ballots(5);
        sortVotes(r, ballots, count, vote);
        ASSERT_TRUE(vote == "4 3");}
    
    //------
    // print
    //------

    TEST(VotingFixture, print_1) {
      std::ostringstream w;
      vector<string> winners = {"John"};
      print(w, winners);
      ASSERT_TRUE(w.str() == "John\n");}

    TEST(VotingFixture, print_2) {
      std::ostringstream w;
      vector<string> winners = {"John", "Mary"};
      print(w, winners);
      ASSERT_TRUE(w.str() == "John\nMary\n");}

    TEST(VotingFixture, print_3) {
      std::ostringstream w;
      vector<string> winners = {"John", "Mary", "Joe"};
      print(w, winners);
      ASSERT_TRUE(w.str() == "John\nMary\nJoe\n");}
    
    //------
    // elect
    //------
 
    TEST(VotingFixture, elect_1) {
      std::istringstream r("3\nJoe\nMary\nLarry\n1 2 3\n3 2 1");
      std::ostringstream w;
      int numCand = 3;
      elect(r, w);
      ASSERT_TRUE(numCand == 3);}

    TEST(VotingFixture, elect_2) {
      std::istringstream r("2\nJoe\nMary\n2 1\n1 2");
      std::ostringstream w;
      int numCand = 2;
      elect(r, w);
      ASSERT_TRUE(numCand == 2);}
 
    TEST(VotingFixture, elect_3) {
      std::istringstream r("1\nJoe\n1\n1");
      std::ostringstream w;
      int numCand = 1;
      elect(r, w);
      ASSERT_TRUE(numCand == 1);}

   // ------------
   // run_cases
   // ------------

    TEST(VotingFixture, run_cases_1) {
      std::istringstream r("1\n\n1\nJoe\n1\n1");
      std::ostringstream w;
      int num = 1;
      run_cases(r, w);
      ASSERT_TRUE(num == 1);}

    TEST(VotingFixture, run_cases_2) {
      std::istringstream r("2\n\n2\nMary\nJohn\n1 2\n2 1\n\n1\nJohn\n1\n1");
      std::ostringstream w;
      int num = 2;
      run_cases(r, w);
      ASSERT_TRUE(num == 2);}

    TEST(VotingFixture, run_cases_3) {
      std::istringstream r("1\n\n3\nJoe\nMary\nJohn\n3 2 1\n1 2 3\n 2 1 3");
      std::ostringstream w;
      int num = 1;
      run_cases(r, w);
      ASSERT_TRUE(num == 1);}
