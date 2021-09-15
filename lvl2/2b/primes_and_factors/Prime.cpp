#include <iostream>

using namespace std;

string check(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return "composite";
        }
    }
    return "prime";
}

int main() {
    int n;
    cin >> n;
    cout << check(n);
    return 0;
}