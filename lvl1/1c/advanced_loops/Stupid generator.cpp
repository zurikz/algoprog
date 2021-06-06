#include <iostream>

using namespace std;

int main() {
    int secs;
    cin >> secs;
    int number = 1;
    int count = number;
    for (int i = 0; i < secs; i++) {
        if (count > 0) {
            cout << number << " ";
            --count;
        } else {
            ++number;
            count = number - 1;
            cout << number << " ";
        }
    }
    return 0;
}