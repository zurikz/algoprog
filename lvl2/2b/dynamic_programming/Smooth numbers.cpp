#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    vector<vector<int>> ans(n + 1, vector<int> (12, 0));
    for (int j = 1; j < 11; j++) {
        ans[1][j] = 1;
    }
    for (int i = 2; i < n + 1; i++) {
        for  (int j = 1; j < 11; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j] + ans[i - 1][j + 1];
        }
    }
    int answer = 0;
    for (int j = 2; j < 11; j++) {
        answer += ans[n][j];
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}