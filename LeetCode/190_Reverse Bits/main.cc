#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;
            int v = ((n & bit) >> i);
            result <<= 1;
            result |= v;
        }

        return result;
    }
};

void init();

int main() {
    uint32_t n = 0b11111111111111111111111111111101;

    init();

    Solution solution;
    uint32_t result = solution.reverseBits(n);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}