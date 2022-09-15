#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            if (tolower(s[left++]) != tolower(s[right--])) {
                return false;
            }
        }

        return true;
    }
};

void init();

int main() {
    string s = "A man, a plan, a canal: Panama";

    init();

    Solution solution;
    bool result = solution.isPalindrome(s);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}