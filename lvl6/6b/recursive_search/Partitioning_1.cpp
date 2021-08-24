#include <iostream>
#include <vector>

using namespace std;

void check(const vector<int>& a) {
    for (size_t i = 1; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

void partition(vector<int>& a, int n) {
    if (n == 0) {
        check(a);
        return;
    }
    for (int j = 1; j <= a.back(); j++) {
        if (n - j >= 0) {
            a.push_back(j);
            partition(a, n - j);
            a.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a = {n};
    partition(a, n);
    return 0;
}