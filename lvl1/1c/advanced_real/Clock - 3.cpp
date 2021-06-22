#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int oneHourAngle = 360 / 12;
const double oneMinuteAngle = oneHourAngle / 60.0;
const double oneSecondAngle = oneMinuteAngle / 60;

string solve(double alpha) {
    int hrs = int(alpha / oneHourAngle);
    alpha -= hrs * oneHourAngle;
    int mins = int(alpha / oneMinuteAngle);
    alpha -= mins * oneMinuteAngle;
    int secs = int(alpha / oneSecondAngle);
    return to_string(hrs) + " " + to_string(mins) + " " + to_string(secs);
}

int main() {
    double alpha;
    cin >> alpha;
    cout << solve(alpha);
    return 0;
}