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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxDepth = 1;
        checkMaxDepth(root, maxDepth, &maxDepth);
        return maxDepth;
    }

    void checkMaxDepth(TreeNode* root, int depth, int* maxDepth) {
        if (root == nullptr) {
            return;
        }
        *maxDepth = max(*maxDepth, depth);
        checkMaxDepth(root->left, depth + 1, maxDepth);
        checkMaxDepth(root->right, depth + 1, maxDepth);
    }
};

void init();

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3, nullptr, nullptr), new TreeNode(4, nullptr, nullptr)), new TreeNode(2, new TreeNode(4, nullptr, nullptr), new TreeNode(3, nullptr, nullptr)));

    init();

    Solution solution;
    int result = solution.maxDepth(root);
    
    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}