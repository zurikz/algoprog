#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    vector<bool> sieve(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        for (int j = i * i; j <= n; j += i) {
            sieve[j] = false;
        }
    }
    for (int i = 2; i < sieve.size(); i++) {
        if (sieve[i] && sieve[n - i]) {
            cout << i << " " << n - i;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}