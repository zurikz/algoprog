#include <iostream>

using namespace std;

int main() {
    int hrs, mins, secs;
    cin >> hrs >> mins >> secs;
    secs = hrs * 60 * 60 + mins * 60 + secs;

    double degree;
    degree = 360 * (double(secs) / (12 * 60 * 60));
    cout << degree;

    return 0;
}