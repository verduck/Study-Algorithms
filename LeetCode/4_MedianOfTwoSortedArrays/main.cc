#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(v));

        int mid = v.size() / 2;
        if (v.size() % 2 == 0) {
            return (v[mid - 1] + v[mid]) / 2.0;
        } else {
            return v[mid];
        }
    }
};

void init();

int main() {
    vector<int> nums1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4 };
    vector<int> nums2 = { 1, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4 };

    init();

    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}