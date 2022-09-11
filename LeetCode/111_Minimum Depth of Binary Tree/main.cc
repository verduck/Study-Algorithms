#include <iostream>
#include <cmath>

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else if (root->left == nullptr || root->right == nullptr) {
            return 1 + max(minDepth(root->left), minDepth(root->right));
        }

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

void init();

int main() {
    TreeNode* root = new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4, nullptr, new TreeNode(5, nullptr, new TreeNode(6, nullptr, nullptr)))));

    init();

    Solution solution;
    int result = solution.minDepth(root);
    
    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}