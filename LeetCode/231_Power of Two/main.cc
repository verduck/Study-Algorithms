#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        double a = log2(abs(n));
        return a - static_cast<int>(a) == 0;
    }
};

void init();

int main() {
    int n = 16;

    init();

    Solution solution;
    bool result = solution.isPowerOfTwo(n);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}