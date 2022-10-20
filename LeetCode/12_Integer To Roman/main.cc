#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<int, char> valueToSymbol = {
        { 1, 'I' },
        { 5, 'V' },
        { 10, 'X' },
        { 50, 'L' },
        { 100, 'C' },
        { 500, 'D' },
        { 1000, 'M' }
    };

    string intToRoman(int num) {
        string answer;
        int i = 1;

        while (num) {
            int n = num % 10;
            if (n % 5 == 4) {
                answer = string(1, valueToSymbol[i]) + string(1, valueToSymbol[(n / 5 + 1) * 5 * i]) + answer;
            } else {
                auto it = valueToSymbol.find((n / 5) * 5 * i);
                answer = (it != valueToSymbol.end() ? string(1, it->second) : "") + string(n % 5, valueToSymbol[i]) + answer;
            }
            num /= 10;
            i *= 10;
        }

        return answer;
    }
};

void init();

int main() {
    int num = 3;

    init();

    Solution solution;
    string result = solution.intToRoman(num);
    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}