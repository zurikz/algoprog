#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int seq(int n) {
    vector<int> ans(n + 1);
    ans[0] = ans[1] = 1;
    for (size_t i = 2; i < ans.size(); i++) {
        if (i % 2 == 0) {
            ans[i] = ans[i / 2] + ans[(i / 2) - 1];
        } else {
            ans[i] = ans[i / 2] - ans[(i / 2) - 1];
        }
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << seq(n);
    return 0;
}