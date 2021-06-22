#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const int oneHourAngle = 360 / 12;

double solve(double alpha) {
    double moduloHourAngle = alpha - oneHourAngle * (int(alpha) / oneHourAngle);
    return 12 * moduloHourAngle;
}

int main() {
    double alpha;
    cin >> alpha;
    cout << solve(alpha);
    return 0;
}