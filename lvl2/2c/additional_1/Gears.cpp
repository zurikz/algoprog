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

int main() {
    int a, b;
    cin >> a >> b;
    cout << (a / gcd(a, b)) * b;
    return 0;
}