#include <iostream>

using namespace std;

int main() {
    int pre, x, count, maxcount;
    cin >> x;
    pre = x;
    count = maxcount = 1;
    while (x != 0) {
        cin >> x;
        if (x == pre) {
            ++count;
        } else {
            count = 1;
        }
        pre = x;
        if (count > maxcount) {
            maxcount = count;
        }
    }
    cout << maxcount;
    return 0;
}