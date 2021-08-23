#include <iostream>
#include <vector>

using namespace std;

void check(const vector<int>& a) {
    for (const int& x : a) {
        cout << x;
    }
    cout << '\n';
}

void partition(vector<int>& a, int n, int sum) {
    if (sum == n) {
        check(a);
        return;
    }
    if (a.size() == 0) {
        for (int j = n; j > 0; --j) {
            a.push_back(j);
            sum += j;
            partition(a, n, sum);
            sum -= j;
            a.pop_back();
        }
    } else {
        int bound = min(n - sum, a.back());
        for (int j = bound; j > 0; --j) {
            a.push_back(j);
            sum += j;
            partition(a, n, sum);
            sum -= j;
            a.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    partition(a, n, 0);
    return 0;
}