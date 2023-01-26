#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one = 0;
        int flip = 0;

        for (char ch : s) {
            if (ch == '1') {
                one++;
            } else if (one > 0) {
                flip++;
            }
            flip = min(one, flip);
        }

        return flip;
    }
};

void init();

int main() {
    string s = "0101100011";

    init();

    Solution solution;
    int result = solution.minFlipsMonoIncr(s);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}