#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int solve(int n, int m) {
    if ((n == 1) || (m == 1)) {
        return max(n, m);
    } else {
        return 1 + gcd(n - 1, m - 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m);
    return 0;
}