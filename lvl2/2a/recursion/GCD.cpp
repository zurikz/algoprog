#include <iostream>

using namespace std;

int recGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return recGCD(b, a % b);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << recGCD(a, b);
    return 0;
}