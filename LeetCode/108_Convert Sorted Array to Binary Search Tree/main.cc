#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size());
    }

    TreeNode* arrayToBST(const vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        return new TreeNode(nums[mid], arrayToBST(nums, left, mid), arrayToBST(nums, mid + 1, right));
    }
};

void init();
void printInorder(TreeNode* root);

int main() {
    vector<int> nums = { -10, -3, 0, 5, 9 };

    init();

    Solution solution;
    TreeNode* result = solution.sortedArrayToBST(nums);
    
    printInorder(result);
}

void printInorder(TreeNode* root) {
    if (root == nullptr) {
        cout << "nullptr "; 
        return;
    }
    cout << root->val << ' ';
    printInorder(root->left);
    printInorder(root->right);
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}