#include <iostream>
#include <string>

using namespace std;

void check(const string& str) {
    cout << str << '\n';
}

void find(string& str, int i) {
    if (i == str.size()) {
        check(str);
        return;
    }
    str[i] = '0';
    find(str, i + 1);
    str[i] = '1';
    find(str, i + 1);
}

int main() {
    int n;
    cin >> n;
    string str(n, ' ');
    find(str, 0);
    return 0;
}