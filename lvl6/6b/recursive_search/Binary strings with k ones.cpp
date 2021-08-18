#include <iostream>
#include <string>

using namespace std;

void find(string s, int n, int k) {
    if (n == 0) {
        cout << s << '\n';
        return;
    }
    if (n > k) {
        find(s + "0", n - 1, k);
    }
    if (k > 0) {
        find(s + "1", n - 1, k - 1);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    find("", n, k);
    return 0;
}