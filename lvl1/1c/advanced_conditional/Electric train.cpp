#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int solution(int i, int j) {
    if (i == j) {
        return 0;
    } else {
        return i + j - 1;
    }
}

int main() {
    int i, j;
    cin >> i >> j;
    cout << solution(i, j);
    return 0;
}