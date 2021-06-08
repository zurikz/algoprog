#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int lineIndex(int n, const vector<int>& heights, int petya) {
    int pos = 1;
    for (const int& height : heights) {
        if (petya <= height) {
            ++pos;
        } else {
            return pos;
        }
    }
    return pos;
}

int main() {
    int n, petya;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cin >> petya;
    cout << lineIndex(n, heights, petya);
    return 0;
}