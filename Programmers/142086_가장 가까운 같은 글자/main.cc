#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> history(26, -1);

    for (int i = 0; i < s.size(); i++) {
        int j = s[i] - 'a';
        if (history[j] == -1) {
            answer.push_back(-1);
        } else {
            answer.push_back(i - history[j]);
        }

        history[j] = i;
    }

    return answer;
}

int main() {
    string s = "banana";
    
    vector<int> result = solution(s);
    for (int i : result) {
        cout << i << ' ';
    }
    return 0;
}