#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int megaGCD(const vector<int>& vec) {
    int d = vec[0];
    for (size_t i = 1; i < vec.size(); i++) {
        d = gcd(d, vec[i]); 
    }
    return d;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& x : vec) {
        cin >> x;
    }
    cout << megaGCD(vec);
    return 0;
}