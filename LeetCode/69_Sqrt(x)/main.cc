#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int answer = 1;
        int left = 2;
        int right = x / 2;

        if (x == 0) {
            return 0;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};

void init();

int main() {
    int x = 8;

    init();

    Solution solution;
    int result = solution.mySqrt(x);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}