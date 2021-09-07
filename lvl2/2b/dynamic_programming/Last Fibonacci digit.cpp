#include <iostream>
#include <vector>

using namespace std;

int lastFibDigit(int n) {
    vector<int> ans(3);
    ans[0] = ans[1] = 1;
    for (size_t i = 2; (int) i <= n; i++) {
        ans[i % 3] = (ans[(i - 1) % 3] + ans[(i - 2) % 3]) % 10;
    }
    return ans[n % 3];
} 

int main() {
    int n;
    cin >> n;
    cout << lastFibDigit(n);
    return 0;
}