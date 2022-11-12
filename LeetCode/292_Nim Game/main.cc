#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

void init();

int main() {
    int n = 4;

    init();

    Solution solution;
    bool result = solution.canWinNim(n);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}