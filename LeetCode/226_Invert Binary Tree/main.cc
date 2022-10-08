#include <iostream>
#include <queue>

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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }

    void invert(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        invert(root->left);
        invert(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
};

void init();

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << ' ';
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    init();

    inorderTraversal(root);
    cout << '\n';

    Solution solution;
    TreeNode* result = solution.invertTree(root);
    inorderTraversal(result);
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}