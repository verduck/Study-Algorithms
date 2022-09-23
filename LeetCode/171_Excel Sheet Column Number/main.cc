#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;

        for (char ch : columnTitle) {
            answer = 26 * answer + (ch - 64);
        }

        return answer;
    }
};

void init();

int main() {
    string columnTitle = "Z";

    init();

    Solution solution;
    int result = solution.titleToNumber(columnTitle);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}