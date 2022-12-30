#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void decomposition(const string& s, int i, int* answer) {
    char ch = s[i];
    pair<int, int> p = { 0, 0 };
    for (int j = i; j < s.size(); j++) {
        if (s[j] == ch) {
            p.first++;
        } else {
            p.second++;
        }
        if (p.first == p.second) {
            (*answer)++;
            decomposition(s, j + 1, answer);
            return;
        } else if (j == s.size() - 1) {
            (*answer)++;
        }
    }
}

int solution(string s) {
    int answer = 0;
    decomposition(s, 0, &answer);
    return answer;
}

int main() {
    string s = "aaabbaccccabba";

    int result = solution(s);
    cout << result << '\n';
    return 0;
}