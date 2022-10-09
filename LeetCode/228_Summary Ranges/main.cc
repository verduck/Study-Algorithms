#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if (nums.empty()) {
            return answer;
        }
        int a = nums[0];
        int b = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i] - 1) {
                b = nums[i];
            } else {
                answer.push_back(rangeToString(a, b));
                a = nums[i];
                b = nums[i];
            }
        }
        answer.push_back(rangeToString(a, b));

        return answer;
    }

    string rangeToString(int a, int b) {
        if (a != b) {
            return to_string(a) + "->" + to_string(b);
        } else {
            return to_string(a);
        }
    }
};

void init();

int main() {
    vector<int> nums = {};

    init();


    Solution solution;
    vector<string> result = solution.summaryRanges(nums);
    
    for (const string& s : result) {
        cout << s << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}