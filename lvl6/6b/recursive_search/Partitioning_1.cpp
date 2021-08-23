#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>& a, int n, int sum, vector<vector<int>>& answer) {
    if (sum == n) {
        answer.push_back(a);
        return;
    }
    int bound;
    if (sum == 0) {
        bound = n;
    } else {
        bound = min(n - sum, a.back());
    }
    for (int j = bound; j > 0; --j) {
        a.push_back(j);
        sum += j;
        partition(a, n, sum, answer);
        sum -= j;
        a.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    vector<vector<int>> answer;
    partition(a, n, 0, answer);
    for (int i = answer.size() - 1; i >= 0; --i) {
        for (const int& x : answer[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}