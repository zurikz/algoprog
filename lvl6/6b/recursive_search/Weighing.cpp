#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

void combine(vector<int>& a, int n, int k, int i, vector<vector<int>>& answer) {
    if (i == k) {
        answer.push_back(a);
        return;
    }
    if (i == 0) {
        for (int j = 0; j < n - k + 1; j++) {
            a[i] = j;
            combine(a, n, k, i + 1, answer);
        }
    } else {
        for (int j = a[i - 1] + 1; j <= n - (k - i); j++) {
            a[i] = j;
            combine(a, n, k, i + 1, answer);
        }
    }
}

void Combinations(int n, int k, vector<vector<int>>& combinations) {
    vector<int> a(k);
    combine(a, n, k, 0, combinations);
}

vector<vector<int>> getAllCombinations(int n) {
    vector<vector<int>> combinations;
    for (int i = 0; i <= n; ++i) {
        Combinations(n, i, combinations);
    }
    return combinations; 
}

int calcWeight(const vector<int>& indices, const vector<int>& weights) {
    int sum = 0;
    for (const int& i : indices) {
        sum += weights[i];
    }
    return sum;
}

string solve(int k, const vector<int>& weights) {
    vector<vector<int>> combinations = getAllCombinations(weights.size());
    for (size_t left = 0; left < combinations.size() - 1; left++) {
        vector<bool> was(weights.size(), false);
        for (const int& idx : combinations[left]) {
            was[idx] = true;
        }

        vector<int> unused;
        for (size_t i = 0; i < weights.size(); i++) {
            if (!was[i]) {
                unused.push_back(i);
            }
        }

        vector<vector<int>> rightCombinations = getAllCombinations(unused.size());
        for (auto& comb : rightCombinations) {
            if (left == 0) continue;
            for (size_t i = 0; i < comb.size(); i++) {
                comb[i] = unused[i];
            }
        }
        for (size_t right = 1; right < rightCombinations.size(); right++) {
            int leftWeight = k + calcWeight(combinations[left], weights);
            int rightWeight = calcWeight(rightCombinations[right], weights);
            if (leftWeight == rightWeight) {
                string answer;
                if (combinations[left].empty()) {
                    answer += "0";
                } else {
                    for (const int& i : combinations[left]) {
                        answer += to_string(weights[i]) + " ";
                    }
                    answer.pop_back();
                }
                answer += "\n";
                for (const int& i : rightCombinations[right]) {
                    answer += to_string(weights[i]) + " ";
                }
                answer.pop_back();
                return answer;
            }
        }
    }
    return "-1";
}

/****** testing *******/

const bool TEST = 0;

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
    int count = 1;
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