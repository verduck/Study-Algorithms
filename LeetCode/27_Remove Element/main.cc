#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};

void init();

int main() {
    vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val = 2;

    init();

    Solution solution;
    int result = solution.removeElement(nums, val);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}