#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int n = numRows - 2;
        if (n < 0) {
            n = 0;
        }
        int row = 0;
        int i = 0;
        int j = numRows + n;
        while (row < numRows && s.size() != result.size()) {
            result += s[i + row];
            if (row != 0 && row != numRows - 1) {
                if (j - row < s.size()) {
                    result += s[j - row];
                    j += numRows + n;
                }
            }
            i += numRows + n;
            if (i + row >= s.size()) {
                row++;
                i = 0;
                j = numRows + n;
            }
           
        }
        return result;
    }
};

void init();

int main() {
    string s = "A";
    int numRows = 2;

    init();

    Solution solution;
    cout << solution.convert(s, numRows) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}