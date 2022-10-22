#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string answer;
        string temp;
        unordered_map<char, int> counts;
        int left = 0;
        int right = 0;

        for (char ch: t) {
            counts[ch]++;
        }

        char ch = s[right];
        temp += ch;
        if (counts.find(ch) != counts.end()) {
            counts[ch]--;
        }

        while (left <= right && right != s.size()) {
            if (isAllContains(counts)) {
                if (answer.empty()) {
                    answer = temp;
                } else {
                    answer = answer.size() > temp.size() ? temp : answer;
                }
                left++;
                if (counts.find(temp[0]) != counts.end()) {
                    counts[temp[0]]++;
                }
                temp = temp.substr(1);
            } else {
                right++;
                ch = s[right];
                temp += ch;
                if (counts.find(ch) != counts.end()) {
                    counts[ch]--;
                }
            }
        }

        return answer;
    }

    bool isAllContains(const unordered_map<char, int>& counts) {
        for (auto it = counts.begin(); it != counts.end(); it++) {
            if (it->second > 0) {
                return false;
            }
        }

        return true;
    }
};

void init();

int main() {
    string s = "a";
    string t = "aa";

    init();

    Solution solution;
    string result = solution.minWindow(s, t);
    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}