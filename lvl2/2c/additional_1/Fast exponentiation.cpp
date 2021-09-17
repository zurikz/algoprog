#include <iostream>

using namespace std;

double Pow(double a,  int n) {
    double result = 1;
    while (n > 0) {
        if (n % 2 == 0) {
            a *= a;
            n /= 2;
        } else {
            result *= a;
            --n;
        }
    }
    return result;
}

int main() {
    double a;
    int n;
    cin >> a >> n;
    cout << Pow(a, n);
    return 0;
}