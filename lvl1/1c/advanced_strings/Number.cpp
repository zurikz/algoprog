#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solve(const string& input) {
    string answer;
    int len = input.size();
    int count = len % 3;
    for (int i = 0; i < len; i++) {
        if (count == 0) {
            if (i != 0)
                answer += ',';
            count = 3;
            --i;
        } else {
            answer += input[i];
            --count;
        }
    }
    return answer;
}

int main() {
    string input;
    cin >> input;
    cout << solve(input);
    return 0;
}