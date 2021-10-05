#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int solve(vector<vector<int>> table) {
    int n = table.size();
    int m = table[0].size();
    vector<vector<int>> ans(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                ans[i][j] = table[i][j];
            } else if (i - 1 < 0) {
                ans[i][j] = table[i][j] + ans[i][j - 1];
            } else if (j - 1 < 0) {
                ans[i][j] = table[i][j] + ans[i - 1][j];
            } else {
                ans[i][j] = table[i][j] + min(ans[i - 1][j], ans[i][j - 1]);
            }
        }
    }
    return ans[n - 1][m - 1];
}

vector<vector<int>> readInput(istream& in) {
    int n, m;
    in >> n >> m;
    vector<vector<int>> table(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> table[i][j];
        }
    }
    return table;
}

int main() {
    vector<vector<int>> table = readInput(cin);
    cout << solve(table);
    return 0;
}