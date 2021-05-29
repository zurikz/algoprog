#include <iostream>

using namespace std;

int main() {
    double needs[3];
    cin >> needs[0] >> needs[1] >> needs[2];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        double meal[3], amount;
        cin >> meal[0] >> meal[1] >> meal[2] >> amount;
        for (int j = 0; j < 2; j++) {
            needs[j] = needs[j] - amount * meal[j];
        }
    }

    double eps = 1e-6;
    for (int i = 0; i < 2; i++) {
        if (needs[i] > eps) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}