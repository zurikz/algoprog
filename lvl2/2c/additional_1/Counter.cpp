#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int k) {
    vector<int> count(n);
    int maxCount = 0;
    int start = 0;
    while (maxCount < 2) {
        int pos = (start + k - 1) % n;
        ++count[pos];
        maxCount = max(maxCount, count[pos]);
        start = (pos + 1) % n;
    }
    int zeroCount = 0;
    for (const int& x : count) {
        if (x == 0) {
            ++zeroCount;
        }
    }
    return zeroCount;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}