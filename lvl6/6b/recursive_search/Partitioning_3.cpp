#include <iostream>
#include <vector>

using namespace std;

void check(const vector<int>& a) {
    for (size_t i = 1; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

void partition(vector<int>& a, int n, int i) {
    if (n == 0) {
        check(a);
        return;
    }
    for (int j = a[i - 1]; j <= n; j++) {
        if (n - j >= 0) {
            a.push_back(j);
            partition(a, n - j, i + 1);
            a.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a = {1};
    partition(a, n, 1);
    return 0;
}