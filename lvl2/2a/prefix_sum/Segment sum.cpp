#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

const bool TEST = 1;

struct Query {
    unsigned int left;
    unsigned int right;
};

vector<int> segmentSum(const vector<int>& input, const vector<Query>& queries) {
    return {0};
}

/****** testing ******/

tuple readTest(ifstream& file) {
    int n, m;
    file >> n >> m;
    vector<int> input(n);
    for (int& x : input) {
        file >> x;
    }
    vector<Query> queries(m);
    for (Query& q : queries) {
        file >> q.left >> q.right;
    }
    vector<int> answers(m);
    for (int& a : answers) {
        file >> a;
    }
    return tie(input, queries, answers);
}

int test(ifstream& file) {
    while (file) {
        auto [input, queries, answers] = readTest(file);
        vector<int> solutions = segmentSum(input, queries);
        if (solutions != answers) {
            cout << "Failed test!" << endl;
            for (const auto& x : input)
                cout << x << " ";
            cout << endl;
            for (const auto& q : queries)
                cout << q.left << " " << q.right << ", ";
            cout << endl;
            for (const auto& a : answers)
                cout << a << "   ";
            cout << endl;
            for (const auto& s : solutions)
                cout << s << "   ";
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Segment sum.txt");
        test(file);
    } else {
        int n, m;
        cin >> n >> m;
        vector<int> input(n);
        for (int& x : input)
            cin >> x;
        vector<Query> queries(m);
        for (auto& q : queries)
            cin >> q.left >> q.right;
        
        vector<int> solutions = segmentSum(input, queries);
        for (const auto& s : solutions) {
            cout << s << endl;
        }
    }
    return 0;
}