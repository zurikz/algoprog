#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int x, y, steps;
    string direction;
    x = y = 0;
    while (cin >> direction) {
        cin >> steps;
        if (direction == "North") {
            y += steps;
        } else if (direction == "South") {
            y -= steps;
        } else if (direction == "East") {
            x += steps;
        } else if (direction == "West") {
            x -= steps;
        }
    }
    cout << x << " " << y;
    return 0;
}