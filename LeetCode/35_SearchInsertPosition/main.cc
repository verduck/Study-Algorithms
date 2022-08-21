#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        return distance(nums.begin(), l);
    }
};

void init();

int main() {
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 7;

    init();

    Solution solution;
    cout << solution.searchInsert(nums, target) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}