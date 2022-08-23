#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> symbolToValue = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

    int romanToInt(string s) {
        int n = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (symbolToValue[s[i]] < symbolToValue[s[i + 1]]) {
                n -= symbolToValue[s[i]];
            } else {
                n += symbolToValue[s[i]];
            }
        }

        n += symbolToValue[s[s.size() - 1]];

        return n;
    }
};

void init();

int main() {
    string s = "MCMXCIV";

    init();

    Solution solution;
    cout << solution.romanToInt(s) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}