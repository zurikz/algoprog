#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solution(int n) {
    string word;
    int ones = n % 10;
    if (n >= 11 && n <= 14) {
        word = "korov";
    } else if (ones == 1) {
        word = "korova";
    } else if (ones == 2 || ones == 3 || ones == 4) {
        word = "korovy";
    } else if (ones == 0 || (ones >= 5)) {
        word = "korov";
    }
    return to_string(n) + " " + word;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n);
    return 0;
}