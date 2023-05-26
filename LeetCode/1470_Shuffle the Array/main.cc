#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer;
        
        int m = nums.size() / 2;
        for (int i = 0; i < m; i++) {
            answer.push_back(nums[i]);
            answer.push_back(nums[i + m]);
        }

        return answer;
    }
};

void init();

int main() {
    vector<int> nums = { 2,5,1,3,4,7 };
    int n = 3;

    init();

    Solution solution;
    vector<int> result = solution.shuffle(nums, n);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}