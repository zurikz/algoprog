#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solution(int a, int b, int c) {
    if (c < 0) {
        return "NO SOLUTION";
    }
    if (a == 0) {
        if (c * c != b) {
            return "NO SOLUTION";
        } else {
            return "MANY SOLUTIONS";
        }
    }
    if ((c * c - b) % a == 0) {
        return to_string((c * c - b) / a);
    } else {
        return "NO SOLUTION";
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solution(a, b, c);
    return 0;
}