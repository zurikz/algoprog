#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int solve(int n, const vector<int>& wagons) {
    int slices = 0;
    for (int i = 0; i < n - 1; i++) {
        if (wagons[i] != wagons[i + 1] - 1) {
            ++slices;
        }
    }
    return slices;
}

int main() {
    int n;
    cin >> n;
    vector<int> wagons(n);
    for (int i = 0; i < n; i++)
        cin >> wagons[i];
    cout << solve(n, wagons);
    return 0;
}