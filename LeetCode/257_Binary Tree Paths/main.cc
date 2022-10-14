#include <iostream>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        
        build(answer, string(), root);

        return answer;
    }

    void build(vector<string>& answer, string s, TreeNode* root) {
        s += to_string(root->val) + "->";
        if (root->left == nullptr && root->right == nullptr) {
            answer.push_back(s.substr(0, s.size() - 2));
            return;
        }
        if (root->left != nullptr) {
            build(answer, s, root->left);
        }
        if (root->right != nullptr) {
            build(answer, s, root->right);
        }
    }
};

void init();

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5, nullptr, nullptr)), new TreeNode(3, nullptr, nullptr));

    init();

    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);
    
    for (const string& s: result) {
        cout << s << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}