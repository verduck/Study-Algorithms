#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answer;
        int n = nums.size();
        int sum = 0;

        for (int i : nums) {
            sum += i;
        }
        
        answer = (n * (n + 1)) / 2;
        answer -= sum;
        return answer;
    }
};

void init();

int main() {
    vector<int> nums = { 0, 1 };

    init();

    Solution solution;
    int result = solution.missingNumber(nums);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}