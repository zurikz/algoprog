// https://algoprog.ru/material/p619
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

vector<vector<char>> solve(const vector<vector<int>>& input) {
    int n = input.size();
    vector<vector<int>> matrix(n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            matrix[i][j] = input[i - 1][j - 1];
        }
    }
    vector<vector<int>> ans(n + 1, vector<int> (n + 1, 0));
    for (int i = 2; i < n + 1; i++) {
        ans[i][0] = numeric_limits<int>::max();
        ans[0][i] = numeric_limits<int>::max();
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]) + matrix[i][j];
        }
    }
    vector<vector<char>> route(n, vector<char> (n, '-'));
    route[n - 1][n - 1] = '#';
    int i = n - 1;
    int j = n - 1;
    while ((i != 0) || (j != 0)) {
        if (ans[(i + 1) - 1][j + 1] < ans[i + 1][(j + 1) - 1]) {
            route[i - 1][j] = '#';
            --i;
        } else {
            route[i][j - 1] = '#';
            --j;
        }
    }
    return route;
}

/****** testing ******/

const bool TEST = 0;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    out << " ";
    for (const auto& x : vec) {
        out << x << " ";
    }
    out << endl;
    return out;
}

template <typename T>
void readMatrix(istream& in, vector<vector<T>>& matrix, bool isInput) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        string line;
        getline(in, line);
        for (int j = 0; j < n; j++) {
            if (isInput) {
                matrix[i][j] = int(line[j] - '0');
            } else {
                matrix[i][j] = line[j];
            }
        }
    }
}

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        int n;
        file >> n;
        file.ignore();
        vector<vector<int>> input(n, vector<int> (n, 0));
        vector<vector<char>> answer(n, vector<char> (n, '.'));
        readMatrix(file, input, true);
        readMatrix(file, answer, false);
        file.ignore();
        vector<vector<char>> solution = solve(input);
        if (solution != answer) {
            cout << "Failed test no. " << testNum << endl;
            cout << "Solution:" << endl;
            cout << solution;
            cout << "Answer:" << endl;
            cout << answer;
            return 1;
        }
        ++testNum;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Route.txt");
        test(file);
    } else {
        int n;
        cin >> n;
        cin.ignore();
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        readMatrix(cin, matrix, true);
        vector<vector<char>> solution = solve(matrix);
        for (const auto& row : solution) {
            for (const auto& x : row) {
                cout << x;
            }
            cout << endl;
        }
    }
    return 0;
}