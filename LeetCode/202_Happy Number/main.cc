#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;

        while (n != 1 && us.find(n) == us.end()) {
            us.insert(n);
            
            n = sumOfTheSquresOfDigits(n);
        }

        return n == 1;
    }

    int sumOfTheSquresOfDigits(int n) {
        int m = 0;

        while (n) {
            m += pow(n % 10, 2);
            n /= 10;
        }

        return m;
    }
};

void init();

int main() {
    int n = 19;

    init();

    Solution solution;
    bool result = solution.isHappy(n);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}