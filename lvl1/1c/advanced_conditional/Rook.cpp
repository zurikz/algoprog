#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solution(int& col1, int& row1, int& col2, int& row2) {
    if ((col1 == col2) || (row1 == row2)) {
        return "YES";
    }
    return "NO";
}

int main() {
    int col1, row1, col2, row2;
    cin >> col1 >> row1 >> col2 >> row2;
    cout << solution(col1, row1, col2, row2);
    return 0;
}