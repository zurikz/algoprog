#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    int day = 1;
    double eps = 1e-8;
    for (double sum = x; sum < y - eps; sum *= 1.7) {
        ++day;
    }

    cout << day;
    return 0;
}