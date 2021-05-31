#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int nextEven(const int& number) {
    return number + 2 * ((number + 1) % 2) + ((number + 2) % 2);
}

int main() {
    int number;
    cin >> number;
    cout << nextEven(number);
    return 0;
}