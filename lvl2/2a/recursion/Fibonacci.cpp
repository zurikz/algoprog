#include <iostream>

using namespace std;

int Fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << Fibonacci(n);
    return 0;
}