#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

int zeroOneKnapsack(int m, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> ans(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (j >= weights[i - 1]) {
                ans[i][j] = max(
                    ans[i - 1][j],
                    ans[i - 1][j - weights[i - 1]] + values[i - 1]
                );
            } else {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    return ans[n][m];
}

/****** testing ******/

const bool TEST = 0;

tuple<int, vector<int>> readInput(istream& in) {
    int n, m;
    in >> n >> m;
    vector<int> weights(n);
    for (auto& w : weights) {
        in >> w;
    }
    return tie(m, weights);
}

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        auto [m, weights] = readInput(file);
        file.ignore();
        int answer;
        file >> answer;
        file.ignore(2);
        int solution = zeroOneKnapsack(m, weights, weights);
        if (solution != answer) {
            cout << "Failed test no. " << testNum << endl;
            cout << "m = " << m << endl;
            cout << "ans = " << answer << ", sol = " << solution << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("0-1 Knapsack.txt");
        test(file);
    } else {
        auto [m, weights] = readInput(cin);
        cout << zeroOneKnapsack(m, weights, weights);
    }
    return 0;
}