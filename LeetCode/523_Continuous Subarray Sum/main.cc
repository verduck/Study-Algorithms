#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void init();

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um{{0, 0}};
		int sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			if (!um.count(sum % k)) {
				um[sum % k] = i + 1;
			} else if (um[sum % k] < i) {
				return true;
			}
		}
		return false;
    }
};

int main() {
	vector<int> nums = { 23, 2, 4, 6, 7 };
	int k = 6;

	init();

	Solution solution;
	bool result = solution.checkSubarraySum(nums, k);

	cout << boolalpha << result << '\n';
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}