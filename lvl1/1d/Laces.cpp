#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int solve(int a, int b, int l, int N) {
    return a + (N - 1) * 2 * a + (N - 1) * 2 * b + 2 * l;
}

void readTest(ifstream& file, int& a, int& b, int& l, int& N, int& answer) {
    if (file.is_open()) {
        string line;
        getline(file, line);
        file >> a >> b >> l >> N;
        file.ignore();
        getline(file, line);
        file >> answer;
        file.ignore();
        getline(file, line);
    }
}

int test(ifstream& file) {
    while (file) {
        int a, b, l, N, answer;
        readTest(file, a, b, l, N, answer);
        int solution = solve(a, b, l, N);
        if (solution != answer) {
            cout << "Input: " << a << " " 
            << b << " " << l << " " << N << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    ifstream file("Laces.txt");
    test(file);
    return 0;
}