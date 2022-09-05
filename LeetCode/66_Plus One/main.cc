#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; i--) {
            int n = digits[i] + carry;
            carry = n / 10;
            digits[i] = n % 10;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

void init();

int main() {
    vector<int> digits = { 9, 9, 9 };

    init();

    Solution solution;
    vector<int> result = solution.plusOne(digits);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}