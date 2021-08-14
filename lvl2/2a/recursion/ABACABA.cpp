#include <iostream>
#include <string>

using namespace std;

string ABACABA(int n) {
    if (n == 1) {
        return "A";
    }
    string a = ABACABA(n - 1);
    return a + string(1, a[a.length() / 2] + 1) + a;
}

int main() {
    int n;
    cin >> n;
    cout << ABACABA(n);
    return 0;
}