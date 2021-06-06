#include <iostream>

using namespace std;

int main() {
    int x, max, count;
    cin >> x;
    max = x;
    count = 1;
    while (x != 0) {
        cin >> x;
        if (x > max) {
            max = x;
            count = 1;
        } else if (x == max) {
            ++count;
        }
    }
    cout << count;
    return 0;
}