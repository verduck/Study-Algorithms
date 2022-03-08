#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    set<string> history;
    char prev = words[0][0];
    int turn = 0;

    for (const string& s : words) {
        if (prev == s[0] && history.find(s) == history.end()) {
            history.insert(s);
            prev = s[s.size() - 1];
            turn++;
        } else {
            answer[0] = (turn % n) + 1;
            answer[1] = (turn / n) + 1;
            break;
        }
    }

    return answer;
}

int main(void) {
    int n = 2;
    vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
    vector<int> answer = solution(n, words);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}