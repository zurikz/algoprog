#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solution(int k) {
    if ((k > 7) || (k % 3 == 0) || (k == 5)) {
        return "YES";
    }
    return "NO";
}

int main() {
    int k;
    cin >> k;
    cout << solution(k);
    return 0;
}