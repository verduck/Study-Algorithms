#include <iostream>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool answer = false;
        if (root == nullptr) {
            return answer;
        }
        check(root, targetSum, 0, &answer);
        return answer;
    }

    void check(TreeNode* root, int targetSum, int sum, bool* answer) {
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) { // 종단 노드일 경우
            if (sum == targetSum) {
                *answer = true;
            }
            return;
        }
        if (root->left != nullptr) {
            check(root->left, targetSum, sum, answer);
        }
        if (root->right != nullptr) {
            check(root->right, targetSum, sum, answer);
        }
    }
};

void init();

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, nullptr), nullptr);
    int targetSum = 1;

    init();

    Solution solution;
    bool result = solution.hasPathSum(root, targetSum);
    
    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}