#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int solution(const int& bound, const int& sec) {
    return -abs((sec % (2 * bound) - bound)) + bound;
}

int main() {
    int bound, sec;
    cin >> bound >> sec;
    cout << solution(bound, sec);
    return 0;
}