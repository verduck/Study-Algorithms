#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> um;

        for (int i : nums) {
            if (um[i]) {
                return true;
            }
            um[i] = true;
        }

        return false;
    }
};

void init();

int main() {
    vector<int> nums = { 1, 2, 3, 1 };

    init();

    Solution solution;
    bool result = solution.containsDuplicate(nums);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}