#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;
            int v = ((n & bit) >> i);
            result += v;
        }

        return result;
    }
};

void init();

int main() {
    uint32_t n = 0b11111111111111111111111111111101;

    init();

    Solution solution;
    int result = solution.hammingWeight(n);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}