#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> freqs(9);
    int x;
    cin >> x;
    while (x != 0) {
        ++freqs[x - 1];
        cin >> x;
    }
    
    for (const int& freq : freqs) {
        cout << freq << " ";
    }
    return 0;
}