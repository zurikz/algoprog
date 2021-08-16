#include <iostream>
#include <vector>

using namespace std;

void check(const vector<int>& a) {
    for (const int& i : a) {
        cout << i + 1;
    }
    cout << '\n';
}

void permute(vector<int>& a, vector<bool>& was, int i) {
    if (i == static_cast<int>(a.size())) {
        check(a);
        return;
    }
    for (int j = 0; j < static_cast<int>(a.size()); j++) {
        if (!was[j]) {
            a[i] = j;
            was[j] = true;
            permute(a, was, i + 1);
            was[j] = false;
        }
    }
}

void Permutations(int n) {
    vector<int> a(n);
    vector<bool> was(n);
    permute(a, was, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    Permutations(n);
    return 0;
}