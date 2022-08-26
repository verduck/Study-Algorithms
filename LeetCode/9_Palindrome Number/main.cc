#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int n = getDigit(x) - 1;
        while (x) {
            int m = pow(10, n);
            int left = x / m;
            int right = x % 10;
            cout << left << ',' << right << '\n';
            if (left != right) {
                return false;
            }
            x %= m;
            x /= 10;
            n -= 2;
        }
        return true;
    }

    int getDigit(int x) {
        int n = 0;

        while (x) {
            x /= 10;
            n++;
        }

        return n;

    }
};

void init();

int main() {
    int x = 41514;

    init();
    
    Solution s;
    bool result = s.isPalindrome(x);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}