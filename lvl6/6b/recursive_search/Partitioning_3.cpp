#include <iostream>
#include <vector>

using namespace std;

void check(const vector<int>& a) {
    for (const int& x : a) {
        cout << x << " ";
    }
    cout << '\n';
}

void partition(vector<int>& a, int n, int sum) {
    if (sum == n) {
        check(a);
        return;
    }
    for (int j = 1; j <= n; j++) {
        a.push_back(j);
        sum += j;
        partition(a, n, sum);
        sum -= j;
        a.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    partition(a, n, 0);
    return 0;
}