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

void voting_solve (istream& r, ostream& w) {

    }

int main () {
    using namespace std;
    voting_solve(cin, cout);
    return 0;}
