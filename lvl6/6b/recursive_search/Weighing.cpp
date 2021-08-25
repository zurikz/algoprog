#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

string solve(int k, const vector<int>& weights) {
    return "";
}

/****** testing *******/

const bool TEST = 1;

tuple<int, vector<int>> readInput(istream& in) {
    int k, n;
    in >> k >> n;
    vector<int> weights(n);
    for (int& w : weights) {
        in >> w;
    }
    return tie(k, weights);
}

int test(ifstream& file) {
    while (file) {
        auto [k, weights] = readInput(file);
        file.ignore();
        string answer;
        getline(file, answer);
        if (answer != "-1") {
            string line;
            getline(file, line);
            answer += "\n" + line;
        }
        file.ignore();
        string solution = solve(k, weights);
        int count = 1;
        if (solution != answer) {
            cout << "Failed test no. " << count << endl;
            cout << "Answer:" << endl << answer << endl;
            cout << "Solution:" << endl << solution;
            return 1;
        }
        ++count;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Weighing.txt");
        test(file);
    } else {
        auto [k, weights] = readInput(cin);
        cout << solve(k, weights);
    }
    return 0;
}