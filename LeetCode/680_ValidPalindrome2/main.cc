#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        return isPalindromeOrPseudoPalindrome(s, 0, s.size() - 1, false);
    }

    bool isPalindromeOrPseudoPalindrome(const string& s, int left, int right, bool isDeleted) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (!isDeleted) {
                    if (isPalindromeOrPseudoPalindrome(s, left + 1, right, true) || isPalindromeOrPseudoPalindrome(s, left, right - 1, true)) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            left++;
            right--;
        }
        return true;
    }
};

void init();

int main() {
    string s;

    init();

    cin >> s;

    Solution solution;
    cout << boolalpha << solution.validPalindrome(s) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}