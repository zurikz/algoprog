#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solve(double alpha) {
    int hrs = int(alpha / 30);
    int mins = int(2 * (alpha - (30 * hrs)));
    int secs = int(120 * (alpha - 30 * hrs - 0.5 * mins));
    return to_string(hrs) + " " + to_string(mins) + " " + to_string(secs);
}

int main() {
    double alpha;
    cin >> alpha;
    cout << solve(alpha);
    return 0;
}