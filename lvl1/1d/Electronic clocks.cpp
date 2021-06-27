#include <iostream>

using namespace std;

void showClocks(int seconds) {
    int hrs = seconds / (60 * 60);
    cout << hrs % 24 << ':';
    int mins = (seconds - hrs * 60 * 60) / 60;
    cout << mins / 10 << mins % 10 << ':';
    int secs = seconds - hrs * 60 * 60 - mins * 60;
    cout << secs / 10 << secs % 10;
}

int main() {
    int seconds;
    cin >> seconds;
    showClocks(seconds);
    return 0;
}