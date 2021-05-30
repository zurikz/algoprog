#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    double sum = 1;
    double factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += 1 / factorial;
    }

    cout << sum;
    return 0;
}