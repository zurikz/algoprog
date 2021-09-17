#include <iostream>

using namespace std;

void primeFactorization(int n) {
    int divisor = 2;
    while (divisor <= n / divisor) {
        if (n % divisor == 0) {
            cout << divisor;
            n = n / divisor;
            cout << '*';
        } else {
            ++divisor;
        }
    }
    cout << n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    primeFactorization(n);
    return 0;
}