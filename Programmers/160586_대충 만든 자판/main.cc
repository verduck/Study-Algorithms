#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> counts('Z' - 'A' + 1, INT_MAX);

    for (const string& s : keymap) {
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'A';
            counts[index] = min(counts[index], i + 1);
        }
    }

    for (const string& s : targets) {
        int n = 0;
        for (const char ch : s) {
            int index = ch - 'A';
            int m = counts[index];

            if (m == INT_MAX) {
                n = -1;
                break;
            }

            n += counts[index];
        }
        answer.push_back(n);
    }

    return answer;
}

int main() {
    vector<string> keymap = { "AA" };
    vector<string> targets = { "B" };

    vector<int> result = solution(keymap, targets);
    
    for (int i : result) {
        cout << i << '\n';
    }

    return 0;
}