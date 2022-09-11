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
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left, root->right);
    }

    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if (left == right) {
            return true;
        } if (left == nullptr || right == nullptr) {
            return false;
        }
        if (!checkSymmetric(left->left, right->right)) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        if (!checkSymmetric(left->right, right->left)) {
            return false;
        }
        return true;
    }
};

void init();

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3, nullptr, nullptr), new TreeNode(4, nullptr, nullptr)), new TreeNode(2, new TreeNode(4, nullptr, nullptr), new TreeNode(3, nullptr, nullptr)));

    init();

    Solution solution;
    bool result = solution.isSymmetric(root);
    
    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}