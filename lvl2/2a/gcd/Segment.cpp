#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const bool TEST = 1;

struct Point {
    int x;
    int y;
};

int solve(Point a, Point b) {
    return cells;
}

/****** testing ******/

void readTest(ifstream& file, Point& a, Point& b, int& answer) {
    file >> a.x >> a.y >> b.x >> b.y;
    file.ignore();
    string line;
    getline(file, line);
}

int test(ifstream& file) {
    while (file) {
        Point a, b;
        int answer;
        readTest(file, a, b, answer);
        int solution = solve(a, b);
        if (solution != answer) {
            cout << "Failed test!" << endl;
            cout << "Input: " << a.x << " " << a.y << endl;
            cout << "       " << b.x << " " << b.y << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Reduction.txt");
        test(file);
    } else {
        Point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        cout << solve(a, b);
    }
    return 0;
}