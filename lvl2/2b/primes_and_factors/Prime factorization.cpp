#include <iostream>

using namespace std;

void primeFactorization(int n) {
    int divisor = 2;
    while (divisor * divisor <= n) {
        if (n % divisor == 0) {
            cout << divisor;
            n = n / divisor;
            cout << '*';
        } else if (divisor == 2) {
            divisor = 3;
        } else {
            divisor += 2;
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