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
      ASSERT_FALSE(bad);
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
<<<<<<< HEAD
    Candidate can_1;
    can_1.name = "John Doe";
    Candidate can_2;
    can_2.name = "Jane Smith";
    Candidate can_3;
    can_3.name = "Sihran Sihran";
    vector<Candidate> candidates = {can_1, can_2, can_3};
    vector<Candidate> losers;
    vector<int> ballot_1 = {3, 1, 2};
    vector<int> ballot_2 = {3, 2, 1};
    vector<int> ballot_3 = {1, 2, 3};
    vector<int> ballot_4 = {3, 1, 2};
    assign_ballot(candidates, 0, ballot_1);
    assign_ballot(candidates, 0, ballot_2);
    assign_ballot(candidates, 0, ballot_3);
    assign_ballot(candidates, 0, ballot_4);
    ostringstream w;
<<<<<<< HEAD
    ASSERT_TRUE(winner(candidates, w));
<<<<<<< HEAD
=======
    ASSERT_TRUE(winner(candidates, w, losers));
>>>>>>> how
}

TEST(VotingFixture, winner_2) {
=======
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
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    vector<Candidate> losers;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ostringstream w;
<<<<<<< HEAD
<<<<<<< HEAD
    ASSERT_FALSE(winner(candidates, w));
=======
    ASSERT_FALSE(winner(candidates, w, losers));
>>>>>>> how
}

TEST(VotingFixture, is_tie_1) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n3 2 1");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    vector<Candidate> losers;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ostringstream w;
<<<<<<< HEAD
=======
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308
    bool c = is_tie(candidates, w);
=======
    bool c = is_tie(candidates, w, losers);
>>>>>>> how
    ASSERT_TRUE(c);
}

TEST(VotingFixture, is_tie_2) {
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
    ostringstream w;
    bool c = is_tie(candidates, w, losers);
    ASSERT_FALSE(c);
}

TEST(VotingFixture, is_tie_3) {
    string s("3\nJohn Doe\nJane Smith\nSirhan Sirhan");
    istringstream test_stream(s);
    vector<Candidate> candidates;
    vector<Candidate> losers;
    int numNames;
    string str;
    getline(test_stream, str);
    istringstream (str) >> numNames;
    get_candidates(test_stream, numNames, candidates);
    get_ballots(test_stream, candidates, numNames);
    ostringstream w;
    bool c = is_tie(candidates, w, losers);
    ASSERT_TRUE(c);
<<<<<<< HEAD
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
    eliminate(candidates, losers);
    ASSERT_TRUE(candidates[0].elim);
    ASSERT_FALSE(candidates[1].elim);
    ASSERT_FALSE(candidates[2].elim);
=======
>>>>>>> fc345f8780a41c894ef847b7ce8fc9029fe29308
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
    eliminate(candidates, losers);
    ASSERT_TRUE(candidates[0].elim);
    ASSERT_FALSE(candidates[1].elim);
    ASSERT_FALSE(candidates[2].elim);
}
=======
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
>>>>>>> a20dfa4c3b563ae4bc24f840bd09213c1889aaa0
