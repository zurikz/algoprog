#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> moves = {
    {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0},
    {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}
};

int solve(int len) {
    vector<int> a(10, 1);
    for (int i = 1; i < len; i++) {
        vector<int> a_next(10);
        for (int num = 0; num <= 9; num++) {
            for (const int& destination : moves[num]) {
                a_next[num] += a[destination];
            }
        }
        a = a_next;
    }
    int sum = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (i != 0 && i != 8) {
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}