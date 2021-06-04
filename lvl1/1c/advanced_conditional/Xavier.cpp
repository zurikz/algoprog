#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int solution(int birth, int death) {
    birth -= 1605;
    death -= 1605;
    if (birth < 0) {
        birth = -10;
    } 
    if (death < 0) {
        return 0;
    }
    return (death - (death % 10) - (birth - (birth % 10))) / 10;
}

int main() {
    int birth, death;
    cin >> birth >> death;
    cout << solution(birth, death);
    return 0;
}