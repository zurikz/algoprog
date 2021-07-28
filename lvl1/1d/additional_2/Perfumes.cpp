#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int flasks, types;
    cin >> flasks >> types;
    double flasksData[flasks + 1][types + 1];
    for (int i = 1; i <= flasks; i++) {
        int type;
        double volume;
        cin >> type >> volume;
        flasksData[i][type] = volume;
    }

    int k;
    cin >> k; 
    for (int i = 0; i < k; i++) {
        int originFlask, destinationFlask, percent;
        cin >> originFlask >> destinationFlask >> percent;
        for (int type = 1; type <= types; type++) {
            double volume = flasksData[originFlask][type] * (percent / 100.0);
            flasksData[destinationFlask][type] += volume;
            if (flasksData[destinationFlask][type] < 10e-10) {
                flasksData[destinationFlask][type] = 0;
            }
            flasksData[originFlask][type] -= volume;
            if (flasksData[originFlask][type] < 10e-10) {
                flasksData[originFlask][type] = 0;
            }
        }
    }

    double sum = 0;
    for (int type = 1; type <= types; type++) {
        sum += flasksData[1][type];
    }

    // cout << endl;
    // for (int flask = 1; flask <= flasks; flask++) {
    //     for (int type = 1; type <= types; type++) {
    //         cout << flasksData[flask][type] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int type = 1; type <= types; type++) {
        cout << fixed << setprecision(3) << 100 * flasksData[1][type] / sum << " ";
    }
    return 0;
}