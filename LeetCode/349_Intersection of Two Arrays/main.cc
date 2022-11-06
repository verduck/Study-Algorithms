#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init();

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> answer;

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(answer));

		answer.erase(unique(answer.begin(), answer.end()), answer.end());

		return answer;
    }
};

int main() {
	vector<int> nums1 = { 4, 9, 5 };
	vector<int> nums2 = { 9, 4, 9, 8, 4 };

	init();

	Solution solution;
	vector<int> result = solution.intersection(nums1, nums2);

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