#include <iostream>
#include <vector>

using namespace std;

long int solve(int n, int m) {
    vector<vector<int>> v(n + 1, vector<int> (m + 1, 0));
    v[0][1] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
    }
    return v[n][m];
}

/****** testing ******/

const bool TEST = 0;

long int answer(int n, int m) {
    long int ans = 1;
    int m_fact = 1;
    for (int i = n; i <= n + m - 2; i++) {
        ans *= i;
        m_fact *= (i - n + 1);
    }
    return ans / m_fact;
}

int test() {
    for (int n = 1; n <= 10; n++) {
        for (int m = 1; m <= 10; m++) {
            if (solve(n, m) != answer(n, m)) {
                cout << "Failed test!\n";
                cout << "n = " << n << " m = " << m << endl;
            }
        }
    }
    cout << "OK!" << endl;
    return 0;
}

int main() {
    if (TEST) {
        test();
    } else {
        int n, m;
        cin >> n >> m;
        cout << answer(n, m);
    }
    return 0;
}