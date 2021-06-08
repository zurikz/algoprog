#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int fibonacci(int n) {
    vector<int> vec(n + 1);
    vec[0] = 1;
    vec[1] = 1;
    for (int i = 2; i < n; i++) {
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    return vec[n - 1];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}