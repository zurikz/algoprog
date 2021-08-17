// https://notes.algoprog.ru/backtrack/index.html
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
    for (auto& x : vec) {
        in >> x;
    }
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (const auto& x : vec) {
        out << x << " ";
    }
    out << endl;
    return out;
}

void check(const vector<int> a) {
    for (const auto& x : a) {
        cout << x;
    }
    cout << '\n';
}

void combine(vector<int>& a, int n, int k, int i) {
    if (i == k) {
        check(a);
        return;
    }
    if (i == 0) {
        for (int j = 0; j < n - k + 1; j++) {
            a[i] = j;
            combine(a, n, k, i + 1);
        }
    } else {
        for (int j = a[i - 1] + 1; j <= n - (k - i); j++) {
            a[i] = j;
            combine(a, n, k, i + 1);
        }
    }
}

void Combinations(int n, int k) {
    vector<int> a(k);
    combine(a, n, k, 0);
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

void arrange(vector<int>& a, vector<bool>& was, int i) {
    if (i == static_cast<int>(a.size())) {
        check(a);
        return;
    }
    for (int j = 0; j < static_cast<int>(was.size()); j++) {
        if (!was[j]) {
            a[i] = j;
            was[j] = true;
            arrange(a, was, i + 1);
            was[j] = false;
        }
    }
}

void Arrangements(int n, int k) {
    vector<int> a(k);
    vector<bool> was(n);
    arrange(a, was, 0);
}

int main() {
    Arrangements(3, 2);
    return 0;
}