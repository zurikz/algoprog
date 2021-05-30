#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double eps = 1e-10;
    if (abs(a + b - c) < eps) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
