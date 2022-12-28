#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = nums[0] - 1;
        for (int i = 1; i < nums.size(); i++) {
            if (step == -1) {
                return false;
            }
            if (nums[i] > step) {
                step = nums[i];
            }
            step--;
        }

        return true;
    }
};

void init();

int main() {
    vector<int> nums = { 3, 2, 1, 0,4 };

    init();

    Solution solution;
    bool result = solution.canJump(nums);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}