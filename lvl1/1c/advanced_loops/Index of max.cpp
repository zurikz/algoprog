#include <iostream>

using namespace std;

int main() {
    int n, x, max, idx;
    cin >> n >> x;
    max = x;
    idx = 0;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x > max) {
            max = x;
            idx = i;
        }
    }
    cout << idx + 1;
    return 0;
}