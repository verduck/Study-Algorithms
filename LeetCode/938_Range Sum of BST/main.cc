#include <iostream>
#include <vector>

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int answer = 0;
        traverse(root, low, high, &answer);
        return answer;
    }

    void traverse(TreeNode* node, int low, int high, int* answer) {
        if (node == nullptr) {
            return;
        }
        if (node->val >= low && node->val <= high) {
            *answer += node->val;
        }
        traverse(node->left, low, high, answer);
        traverse(node->right, low, high, answer);
    }
};

void init();

int main() {
    TreeNode* root = new TreeNode(10, new TreeNode(5, new TreeNode(3, nullptr, nullptr), new TreeNode(7, nullptr, nullptr)), new TreeNode(15, nullptr, new TreeNode(18, nullptr, nullptr)));
    int low = 7;
    int high = 15;

    init();

    Solution solution;
    int result = solution.rangeSumBST(root, low, high);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}