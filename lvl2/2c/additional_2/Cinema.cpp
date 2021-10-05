#include <iostream>
#include <vector>

using namespace std;

pair<int, int> newCoord(pair<int, int> coord, int n, int m) {
    int num = coord.first * m + coord.second;
    return {num % n, num / n};
}

int solve(int n, int m) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pair<int, int> {i, j} == newCoord({i, j}, n, m)) {
                ++ans;
            }
        }
    }
    return ans;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

// int solve2(int n, int m) {

// }

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    cout << gcd(n - 1, m - 1); 
    
    // int num;
    // cin >> num;
    // pair<int, int> newCoo = newCoord(num, n, m);
    // cout << newCoo.first << " " << newCoo.second;
    return 0;
}