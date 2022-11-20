#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        int result = 0;

        for (int i = left; i <= right; i++) {
            result += nums[i];
        }

        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

void init();

int main() {
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };

    init();

    NumArray* numArray = new NumArray(nums);
    cout << numArray->sumRange(0, 2) << ' ';
    cout << numArray->sumRange(2, 5) << ' ';
    cout << numArray->sumRange(0, 5) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}