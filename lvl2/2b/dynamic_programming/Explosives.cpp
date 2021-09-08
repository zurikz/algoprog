#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    vector<int> ans(n + 1);
    ans[1] = 2; 
    ans[2] = 3;
    for (size_t i = 3; i < ans.size(); i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}