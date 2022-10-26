#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int j = i;
                for (int k = i + 1; k < nums.size(); k++) {
                    if (nums[k] != 0) {
                        int temp = nums[j];
                        nums[j] = nums[k];
                        nums[k] = temp;
                        j = k;
                    }
                }
            }
        }
    }
};

void init();

int main() {
    vector<int> nums = { 0, 0, 1 };

    init();

    Solution solution;
    solution.moveZeroes(nums);

    for (int i : nums) {
        cout << i << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}