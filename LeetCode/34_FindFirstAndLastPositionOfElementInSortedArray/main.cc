#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = { -1, -1 };
        if (nums.empty()) {
            return result;
        }
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto u = upper_bound(nums.begin(), nums.end(), target);
        if (u != nums.begin()) {
            u--;
        }

        if (l != nums.end() && *l == target) {
            result[0] = distance(nums.begin(), l);
        }
        if (*u == target) {
            result[1] = distance(nums.begin(), u);
        }

        return result;
    }
};

void init();

int main() {
    vector<int> nums = { 2, 2 };
    int target = 3;

    init();

    Solution solution;
    vector<int> result = solution.searchRange(nums, target);
    cout << '[' << result[0] << ',' << result[1] << "]\n";
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}