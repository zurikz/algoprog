#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solve(int n, int a, int b) {
    int array[n + 1];
    array[n - 1] = a;
    array[n] = b;
    for (int i = n - 2; i >= 0; --i) {
        array[i] = array[i + 2] - array[i + 1];
    }
    return to_string(array[0]) + " " + to_string(array[1]);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << solve(n, a, b);
    return 0;
}