#include <iostream>

using namespace std;

int solve(int a, int b, int l, int N) {
    return a + (N - 1) * 2 * a + (N - 1) * 2 * b + 2 * l;
}

int main() {
    int a, b, l, N;
    cin >> a >> b >> l >> N;
    cout << solve(a, b, l, N);
    return 0;
}