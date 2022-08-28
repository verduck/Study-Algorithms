#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class SolutionWithSTL {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {
                nums[++k] = nums[i];
            }
        }
        return ++k;
    }
};

void init();

int main() {
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

    init();

    Solution solution;
    int result = solution.removeDuplicates(nums);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}