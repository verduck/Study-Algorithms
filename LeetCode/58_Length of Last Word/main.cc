#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                n++;
            } else if (n != 0) {
                return n;
            }
        }

        return n;
    }
};

void init();

int main() {
    string s = "Hello World  ";

    init();

    Solution solution;
    cout << solution.lengthOfLastWord(s) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}