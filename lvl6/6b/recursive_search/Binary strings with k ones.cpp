#include <iostream>
#include <vector>
#include <string>

using namespace std;

void check(const vector<int>& a, int n, vector<string>& answer) {
    string str(n, '0');
    for (const int& i : a) {
        str[i] = '1';
    }
    answer.push_back(str);
}

void combine(vector<int>& a, int n, int k, int i, vector<string>& answer) {
    if (i == k) {
        check(a, n, answer);
        return;
    }
    if (i == 0) {
        for (int j = 0; j < n - k + 1; j++) {
            a[i] = j;
            combine(a, n, k, i + 1, answer);
        }
    } else {
        for (int j = a[i - 1] + 1; j <= n - (k - i); j++) {
            a[i] = j;
            combine(a, n, k, i + 1, answer);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    vector<string> answer;
    combine(a, n, k, 0, answer);

    for (int i = answer.size() - 1; i >= 0; --i) {
        cout << answer[i] << '\n';
    }
    return 0;
}