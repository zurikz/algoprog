#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int getNextPlayer(int currentPlayer) {
    return (currentPlayer + 1) % 2;
}

string solve(const vector<string>& match) {
    int servicePlayer = 0;
    int currentPlayer = 0;
    int serviceCount = 0;
    vector<int> result = {0, 0};
    for (const string& event : match) {
        if (event == "service") {
            ++serviceCount;
            currentPlayer = servicePlayer;
            if (serviceCount == 5) {
                servicePlayer = getNextPlayer(servicePlayer);
                serviceCount = 0;
            }
        } else if (event == "net") {
            ++result[getNextPlayer(currentPlayer)];
        } else if (event == "out") {
            ++result[getNextPlayer(currentPlayer)];
        } else if (event == "return") {
            currentPlayer = getNextPlayer(currentPlayer);
        } else if (event == "goal") {
            ++result[currentPlayer];
        } else if (event == "eom") {
            break;
        }
    }
    return to_string(result[0]) + " " + to_string(result[1]);
}

/*********** testing ***********/

tuple<vector<string>, string> readTest(ifstream& file) {
    string line;
    getline(file, line);

    vector<string> match;
    getline(file, line);
    while (line != "eom") {
        match.push_back(line);
        getline(file, line);
    }
    match.push_back("eom");
    getline(file, line);

    string answer;
    getline(file, answer);
    getline(file, line);
    return make_tuple(match, answer);
}

int test(ifstream& file) {
    while (file) {
        auto [match, answer] = readTest(file);
        string solution = solve(match);
        if (solution != answer) {
            cout << "Failed test!" << endl;
            for (const string& event : match) {
                cout << event << endl;
            }
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    // ifstream file("Protocol.txt");
    // test(file);
    vector<string> match;
    string event;
    getline(cin, event);
    while (event != "eom") {
        match.push_back(event);
        getline(cin, event);
    }
    match.push_back("eom");

    cout << solve(match);
    return 0;
}