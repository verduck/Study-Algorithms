#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            if (um.find(nums[i]) != um.end()) {
                if (i - um[nums[i]] <= k) {
                    return true;
                }
            }
            um[nums[i]] = i;
        }

        return false;
    }
};

void init();

int main() {
    vector<int> nums = { 1, 2, 3, 1 };
    int k = 3;

    init();

    Solution solution;
    bool result = solution.containsNearbyDuplicate(nums, k);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}