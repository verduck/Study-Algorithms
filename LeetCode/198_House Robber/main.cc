#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 1, 0);
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        memo[1] = nums[0];
        memo[2] = nums[1];

        for (int i = 3; i < nums.size() + 1; i++) {
            memo[i] = max(memo[i - 3] + nums[i - 1], memo[i - 2] + nums[i - 1]);
        }

        return *max_element(memo.begin(), memo.end());
    }
};

void init();

int main() {
    vector<int> nums = { 1, 2, 3, 1 };

    init();

    Solution solution;
    int result = solution.rob(nums);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}