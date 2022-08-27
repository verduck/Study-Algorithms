#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        string s = strs[0];
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i < strs[j].size()) {
                    if (s[i] != strs[j][i]) {
                        return result;
                    }
                } else {
                    return result;
                }
            }
            result += s[i];
        }

        return result;
    }
};

void init();

int main() {
    vector<string> strs = { "flower", "flow", "flight" };

    init();

    Solution solution;
    cout << solution.longestCommonPrefix(strs) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}