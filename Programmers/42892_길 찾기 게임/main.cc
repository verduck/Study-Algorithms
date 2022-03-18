#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class node {
public:
    node(int n, int x, int y) : n_(n), x_(x), y_(y), left_(nullptr), right_(nullptr) {}

    bool operator> (const node& n) {
        if (y_ == n.y_) {
            return x_ < n.x_;
        }
        return y_ > n.y_;
    }
    int n() const { return n_; }
    node* left() const { return left_; }
    node* right() const { return right_; }

    void add_child(const unique_ptr<node>& n) {
        if (n.get() == this) {
            return;
        }
        if (x_ < n->x_) {
            if (right_ == nullptr) {
                right_ = n.get();
            } else {
                right_->add_child(n);
            }
        } else {
            if (left_ == nullptr) {
                left_ = n.get();
            } else {
                left_->add_child(n);
            }
        }
    }
private:
    int n_;
    int x_;
    int y_;
    node* left_;
    node* right_;
};

void preorder(node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->n());
    preorder(root->left(), result);
    preorder(root->right(), result);
}

void postorder(node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left(), result);
    postorder(root->right(), result);
    result.push_back(root->n());
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());
    vector<unique_ptr<node>> nodes;

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodes.push_back(make_unique<node>(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
    }

    sort(nodes.begin(), nodes.end(), [](const unique_ptr<node>& left, const unique_ptr<node>& right) -> bool {
        return *left > *right;
    });

    const unique_ptr<node>& root = nodes[0];
    for (const unique_ptr<node>& n : nodes) {
        root->add_child(n);
    }

    preorder(root.get(), answer[0]);
    postorder(root.get(), answer[1]);
    return answer;
}

int main() { 
    vector<vector<int>> nodeinfo = { { 5, 3 }, { 11, 5 }, { 13, 3 }, { 3, 5 }, { 6, 1 }, { 1, 3 }, { 8, 6 }, { 7, 2 }, { 2, 2 } };
    vector<vector<int>> result = solution(nodeinfo);
    for (const vector<int>& v : result) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}