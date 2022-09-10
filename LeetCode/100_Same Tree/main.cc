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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }
        if (!isSameTree(p->left, q->left)) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        if (!isSameTree(p->right, q->right)) {
            return false;
        }
        return true;
    }
};

void init();

int main() {
    TreeNode* p = new TreeNode(1, new TreeNode(2, nullptr, nullptr), new TreeNode(3, nullptr, nullptr));
    TreeNode* q = new TreeNode(1, new TreeNode(2, nullptr, nullptr), new TreeNode(3, nullptr, nullptr));

    init();

    Solution solution;
    bool result = solution.isSameTree(p, q);
    
    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}