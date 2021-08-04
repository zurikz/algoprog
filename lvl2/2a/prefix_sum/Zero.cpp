#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

const bool TEST = 0;

struct Query {
    unsigned int left, right;
};

vector<int> countZeros(const vector<int>& vec, const vector<Query>& queries) {
    vector<int> prefZero(vec.size() + 1);
    prefZero[0] = 0;
    for (size_t i = 1; i < prefZero.size(); i++) {
        prefZero[i] = prefZero[i - 1] + (vec[i - 1] == 0);
    }
    vector<int> answers;
    for (const Query& q : queries) {
        answers.push_back(prefZero[q.right] - prefZero[q.left - 1]);
    }
    return answers;
}

/****** testing ******/

tuple<vector<int>, vector<Query>> readInput(istream& in) {
    int n;
    in >> n;
    vector<int> vec(n);
    for (int& x : vec) {
        in >> x;
    }
    int k;
    in >> k;
    vector<Query> queries(k);
    for (auto& q : queries) {
        in >> q.left >> q.right;
    }
    return tie(vec, queries);
}

int test(ifstream& file) {
    while (file) {
        auto [vec, queries] = readInput(file);
        vector<int> answers(queries.size());
        for (int& a : answers) {
            file >> a;
        }
        file.ignore(2);
        vector<int> solutions = countZeros(vec, queries);
        if (solutions != answers) {
            cout << "Failed test!" << endl;
            for (const int& x : vec) cout << x << " ";
            cout << endl;
            for (const auto& q : queries)
                cout << q.left << " " << q.right << "   ";
            for (const auto& a : answers)
                cout << a << "     ";
            for (const auto& s : solutions)
                cout << s << "     ";
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Zero.txt");
        test(file);
    } else {
        auto [vec, queries] = readInput(cin);
        vector<int> answers = countZeros(vec, queries);
        for (const auto& a : answers) {
            cout << a << " ";
        }
    }
    return 0;
}