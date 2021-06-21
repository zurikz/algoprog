#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int solve(const double& n) {
    return int(floor(10 * (n - floor(n))));
}

int main() {
    double n;
    cin >> n;
    cout << solve(n);
    return 0;
}