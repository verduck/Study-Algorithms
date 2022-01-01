#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void init();

class node {
public:
  node();
  node(char alpha);

  char get_alpha() const;
  node* get_left() const;
  node* get_right() const;
  void set_left(node* left);
  void set_right(node* right);
private:
  char alpha_;
  node* left_;
  node* right_;
};

node::node() :
  node('A') {}

node::node(char alpha) :
  alpha_(alpha),
  left_(nullptr),
  right_(nullptr) {}

char node::get_alpha() const {
  return alpha_;
}

node* node::get_left() const {
  return left_;
}

node* node::get_right() const {
  return right_;
}

void node::set_left(node* left) {
  left_ = left;
}

void node::set_right(node* right) {
  right_ = right;
}

void preorder(node* root) {
  if (root == nullptr) {
    return;
  }
  cout << root->get_alpha();
  preorder(root->get_left());
  preorder(root->get_right());
}

void inorder(node* root) {
  if (root == nullptr) {
    return;
  }
  inorder(root->get_left());
  cout << root->get_alpha();
  inorder(root->get_right());
  
}

void postorder(node* root) {
  if (root == nullptr) {
    return;
  }
  postorder(root->get_left());
  postorder(root->get_right());
  cout << root->get_alpha();
}

int main() {
  int n;
  unordered_map<char, node> nodes;
  node* root;

  init();

  cin >> n;
  for (int i = 0; i < n; i++) {
    nodes.insert({ 'A' + i, node('A' + i) });
  }

  root = &nodes['A'];

  for (int i = 0; i < n; i++) {
    char p, l, r;
    cin >> p >> l >> r;
    if (l != '.') {
      nodes[p].set_left(&nodes[l]);
    }
    if (r != '.') {
      nodes[p].set_right(&nodes[r]);
    }
  }

  preorder(root);
  cout << "\n";
  inorder(root);
  cout << "\n";
  postorder(root);
  cout << "\n";
  
  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}