#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while (columnNumber > 0) {
            columnNumber--;
            result = static_cast<char>((columnNumber % 26) + 65) + result;
            columnNumber /= 26;
        }

        return result;
    }
};

void init();

int main() {
    int columnNumber = 1;

    init();

    Solution solution;
    string result = solution.convertToTitle(columnNumber);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}