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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        preorder(root, answer);
        return answer;
    }

    void preorder(TreeNode* root, vector<int>& answer) {
        if (root == nullptr) {
            return;
        }
        answer.push_back(root->val);
        preorder(root->left, answer);
        preorder(root->right, answer);
    }
};

void init();

int main() {
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3, nullptr, nullptr), nullptr));

    init();

    Solution solution;
    vector<int> result = solution.preorderTraversal(root);
    
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}