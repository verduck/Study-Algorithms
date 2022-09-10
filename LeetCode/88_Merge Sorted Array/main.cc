#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;

        while (i < n + m && j < n) {
            if (i >= m) {
                swap(nums1[i], nums2[j]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                i++;
                sort(nums2.begin(), nums2.end());
            } else {
                i++;
            }
        }
    }
};

void init();

int main() {
    vector<int> nums1 = { 4, 5, 6, 0, 0, 0 };
    int m = 3;
    vector<int> nums2 = { 1, 2, 3 };
    int n = 3;

    init();

    Solution solution;
    solution.merge(nums1, m, nums2, n);
    
    for (int i : nums1) {
        cout << i << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}