#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string endOfClass(int n) {
    int minutes = 45 * n;
    if (n % 2 == 0) {
        minutes += 15 * ((n - 1) / 2) + 5 * n / 2;
    } else {
        minutes += 20 * (n - 1) / 2;
    }
    int hours = 9 + minutes / 60;
    return to_string(hours) + " " + to_string(minutes % 60);
}

int main() {
    int n;
    cin >> n;
    cout << endOfClass(n);
    return 0;
}