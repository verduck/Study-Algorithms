#include <iostream>

using namespace std;

const int BAD = 4;

bool isBadVersion(int version) {
    return version >= BAD;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int answer = n;
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = (static_cast<long>(left) + right) / 2;
            if (isBadVersion(mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};

void init();

int main() {
    int n = 5;

    init();

    Solution solution;
    int result = solution.firstBadVersion(n);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}