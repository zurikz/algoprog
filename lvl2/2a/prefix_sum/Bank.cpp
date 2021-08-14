#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

const bool TEST = 0;

vector<int> solve(const vector<int>& vec, int k) {
    vector<int> solution(2);
    int prefMaxIdx = 0;
    int maxSum = -1;
    for (int i = 0; i < vec.size() - k - 1; i++) {
        if (vec[i] > vec[prefMaxIdx]) {
            prefMaxIdx = i;
        }
        int currSum = vec[prefMaxIdx] + vec[i + k + 1];
        if (currSum > maxSum) {
            maxSum = currSum; 
            solution[0] = prefMaxIdx + 1;
            solution[1] = i + k + 2;
        } 
    }
    return solution;
}

/****** testing ******/

istream& operator>>(istream& in, vector<int>& vec) {
    for (auto& x : vec) {
        in >> x;
    }
    return in;
}

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (const auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;
    return out;
}

tuple<vector<int>, int> readInput(istream& in) {
    int n, k;
    in >> n >> k;
    vector<int> vec(n);
    in >> vec;
    return tie(vec, k);
}

int test(ifstream& file) {
    while (file) {
        auto [vec, k] = readInput(file);
        vector<int> answer(2);
        file >> answer;
        file.ignore(2);
        vector<int> solution = solve(vec, k);
        if (answer != solution) {
            cout << "Failed test!" << endl;
            cout << k << endl;
            cout << vec;
            cout << answer;
            cout << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Bank.txt");
        test(file);
    } else {
        auto [vec, k] = readInput(cin);
        vector<int> solution = solve(vec, k);
        cout << solution[0] << " " << solution[1];
    }
    return 0;
}