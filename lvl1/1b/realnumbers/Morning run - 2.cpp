#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    int day = 0;
    double sum = 0;
    double eps = 1e-8;
    for (double x_i = x; sum < y - eps; x_i *= 1.7) {
        sum += x_i;
        ++day;
    }

    cout << day;
    return 0;
}