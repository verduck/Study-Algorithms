#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;

        for (int i : nums) {
            answer ^= i;
        }

        return answer;
    }
};

void init();

int main() {
    vector<int> nums = { 2, 2, 1 };

    init();

    Solution solution;
    int result = solution.singleNumber(nums);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}