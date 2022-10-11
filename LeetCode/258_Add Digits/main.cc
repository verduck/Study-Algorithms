#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num <= 0) {
            return num;
        }
        return 1 + ((num - 1) % 9);
    }
};

void init();

int main() {
    int num = 43;
    init();

    Solution solution;
    int result = solution.addDigits(num);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}