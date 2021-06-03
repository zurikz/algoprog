#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int solution(int kids, int adults, int capacity) {
    if (adults < 2 || capacity < 3) {
        return 0;
    } else if ((adults / 2) * (capacity - 2) >= kids) {
        return ceil(double(kids + adults) / capacity);
    } else {
        return 0;
    }
}

int main() {
    int kids, adults, capacity;
    cin >> kids >> adults >> capacity;
    cout << solution(kids, adults, capacity);
    return 0;
}