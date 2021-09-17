#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> sieve(n + 1, true);
    for (size_t i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (size_t j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

int getKthPrime(int k) {
    int size;
    if (k > 50) {
        size = ceil(k * log(k * log(k)));
    } else {
        size = 250;
    }
    vector<bool> sieve = sieveOfEratosthenes(size);
    int count = 0;
    for (size_t i = 2; i < sieve.size(); i++) {
        if (sieve[i]) {
            ++count;
            if (count == k) {
                return i;
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    cout << getKthPrime(k);
    return 0;
}