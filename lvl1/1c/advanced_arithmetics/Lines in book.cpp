#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(const int& linesPerPage, const int& globalLine) {
    int pageNumber, localLine;
    pageNumber = (globalLine + (linesPerPage - 1)) / linesPerPage;
    localLine = globalLine - (pageNumber - 1) * linesPerPage;
    vector<int> answer = {pageNumber, localLine};
    return answer;
}

int main() {
    int linesPerPage, globalLine;
    cin >> linesPerPage >> globalLine;
    vector<int> answer = solution(linesPerPage, globalLine);
    cout << answer[0] << " " << answer[1];
    return 0;
}