#include <iostream>
#include <vector>

using namespace std;

void init();
int singleNonDuplicate(vector<int>& nums);
int binary_search(vector<int>& nums, int left, int right);

int main() {
  vector<int> nums = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };

  init();

  cout << singleNonDuplicate(nums) << '\n';
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int singleNonDuplicate(vector<int>& nums) {
  return binary_search(nums, 0, nums.size() - 1);
}

int binary_search(vector<int>& nums, int left, int right) {
  if (left > right) {
    return 0;
  }
  if (left == right) {
    return nums[left];
  }

  int mid = (left + right) / 2;
  if (mid % 2 == 0) {
    if (nums[mid] == nums[mid + 1]) { // 다음 거와 같으면 하나인 수가 오른쪽에 있으므로 오른쪽 탐색
      return binary_search(nums, mid + 2, right);
    } else { // 왼쪽 탐색
      return binary_search(nums, left, mid);
    }
  } else {
    if (nums[mid] == nums[mid + 1]) { // 다음 거와 같으면 하나인 수가 왼쪽에 있으므로 왼쪽 탐색
      return binary_search(nums, left, mid - 1);
    } else { // 오른쪽 탐색
      return binary_search(nums, mid + 1, right);
    }
  }
}