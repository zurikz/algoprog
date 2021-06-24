#include <iostream>

using namespace std;

double solve(int n, double x) {
    double sum = 1.0;
    double multiplier = x;
    for (int i = 0; i < n; i++) {
        sum += x;
        x *= multiplier;
    }
    return sum;
}

int main() {
    int n;
    double x;
    cin >> n >> x;
    cout << solve(n, x);
    return 0;
}