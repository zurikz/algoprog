// https://algoprog.ru/material/p668
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

long long int solve(const vector<pair<int, int>>& polygon) {
    long long int answer = 0;
    for (int i = 0; i < polygon.size(); i++) {
        auto point1 = polygon[i];
        auto point2 = polygon[(i + 1) % polygon.size()];
        int a = abs(point1.first - point2.first);
        int b = abs(point1.second - point2.second);
        answer += gcd(a, b) + 1;
    }
    return answer - polygon.size();
}

/****** testing ******/

const bool TEST = 0;

vector<pair<int, int>> readInput(istream& in) {
    int n;
    in >> n;
    vector<pair<int, int>> polygon(n);
    for (auto& point : polygon) {
        in >> point.first >> point.second;
    }
    return polygon;
}

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        auto polygon = readInput(file);
        int answer;
        file >> answer;
        file.ignore(2);
        int solution = solve(polygon);
        if (solution != answer) {
            cout << "Failed test no. " << testNum << endl;
            cout << "Ans: " << answer << ", Sol: " << solution << endl;
            return 1;
        }
        ++testNum;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Polygon.txt");
        test(file);
    } else {
        auto polygon = readInput(cin);
        cout << solve(polygon);
    }
    return 0;
}