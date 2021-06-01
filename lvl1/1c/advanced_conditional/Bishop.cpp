#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solution(int& row1, int& col1, int& row2, int& col2) {
    if (abs(row1 - row2) == abs(col1 - col2)) {
        return "YES";
    }
    return "NO";
}
 
int main() {
    int row1, col1, row2, col2;
    cin >> row1 >> col1 >> row2 >> col2;
    cout << solution(row1, col1, row2, col2);
    return 0;
}