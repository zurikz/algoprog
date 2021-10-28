// https://algoprog.ru/material/p210
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int>& nails) {
    int n = nails.size();
    sort(nails.begin(), nails.end());
    if (n < 4) {
        return nails.back() - nails[0];
    }
    vector<int> ans(n);
    ans[1] = nails[1] - nails[0];
    ans[2] = nails[2] - nails[0];
    for (int i = 3; i < n; i++) {
        ans[i] = min(ans[i - 1], ans[i - 2]) + nails[i] - nails[i - 1];
    }
    return ans.back();
}

/****** testing ******/

const bool TEST = 0;

vector<int> readInput(istream& in) {
    int n;
    in >> n;
    vector<int> input(n);
    for (int& x : input) {
        in >> x;
    }
    return input;
}

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        vector<int> input = readInput(file);
        int answer;
        file >> answer;
        file.ignore(2);
        int solution = solve(input);
        if (solution != answer) {
            cout << "Failed test no. " << testNum << endl;
            for (const int& x : input) cout << x << " ";
            cout << endl;
            cout << "Ans: " << answer << endl;
            cout << "Sol: " << solution << endl;
            return 1;
        }
        ++testNum;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Nails.txt");
        test(file);
    } else {
        vector<int> input = readInput(cin);
        cout << solve(input);
    }
    return 0;
}