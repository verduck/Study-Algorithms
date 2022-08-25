#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> history;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (history.find(diff) == history.end()) {
                history[nums[i]] = i;
            } else {
                return { history[diff], i };
            }
        }

        return { -1, -1 };
    }
};

void init();

int main() {
    vector<int> nums = { 3, 2, 4 };
    int target = 6;

    init();
    
    Solution s;
    vector<int> result = s.twoSum(nums, target);

    cout << '[' << result[0] << ',' << result[1] << ']' << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}