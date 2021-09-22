#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int solve(vector<pair<int, int>>& schedule) {
    int totalSeconds = 9 * 60 * 60;
    vector<int> a(totalSeconds + 1);
    vector<int> time(totalSeconds + 1);
    schedule.push_back({32400, 0});
    for (size_t i = 1; i < schedule.size(); i++) {
        cout << schedule[i].first << " " << schedule[i].second << endl;
        int start = schedule[i - 1].first;
        int end = schedule[i].first - 1;
        for (size_t j = start; j <= end; j++) {
            if ((j >= (13 - 9) * 3600) && (j < (14 - 9) * 3600)) {
                continue;
            }
            time[j] = schedule[i - 1].second;
        }
    }
    for (size_t i = 0; i < totalSeconds; i++) {
        a[i + 1] = max(a[i + 1], a[i]);
        if (i + time[i] > totalSeconds) {
            // return a[i];
            break;
        }
        a[i + time[i]] = max(a[i + time[i]], a[i] + 1);
    }

    for (size_t  i = 32390; i <= totalSeconds + 1; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return a[a.size() - 1];
}

/****** tesing ******/

const bool TEST = 1;

int parseTime(istream& in) {
    int seconds = 0;
    string str;
    getline(in, str, ':');
    seconds += (stoi(str) - 9) * 60 * 60;
    getline(in, str, ':');
    seconds += stoi(str) * 60;
    in >> str;
    seconds += stoi(str);
    return seconds;
}

vector<pair<int, int>> readInput(istream& in) {
    int n;
    in >> n;
    vector<pair<int, int>> schedule;
    for (int i = 0; i < n; i++) {
        int startTime = parseTime(in);
        int secPerNail;
        in >> secPerNail;
        schedule.push_back({startTime, secPerNail});
    }
    return schedule;
}

int test(ifstream& file) {
    while (file) {
        auto schedule = readInput(file);
        int answer;
        file >> answer;
        file.ignore(2);
        int solution = solve(schedule);
        if (solution != answer) {
            cout << "Failed test!\n";
            cout << "Ans: " << answer << ", Sol: " << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Karlo.txt");
        test(file);
    } else {
        auto schedule = readInput(cin);
        cout << solve(schedule);
    }
    return 0;
}