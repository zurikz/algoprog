#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solution(int n, int m, int k) {
    if (((k % n == 0) || (k % m == 0)) && (k < n * m)) {
        return "YES";
    }
    return "NO";
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << solution(n, m, k);
    return 0;
}