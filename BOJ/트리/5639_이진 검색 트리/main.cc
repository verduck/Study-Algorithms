#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void init();

class node {
public:
  node();
  node(int n);
  
  int get_n() const;
  node* get_left() const;
  node* get_right() const;
  void add_child(int n);
private:
  int n_;
  unique_ptr<node> left_;
  unique_ptr<node> right_;
};

node::node() :
  node(0)  {}

node::node(int n) :
  n_(n),
  left_(nullptr),
  right_(nullptr) {}

int node::get_n() const {
  return n_;
}

node* node::get_left() const {
  return left_.get();
}

node* node::get_right() const {
  return right_.get();
}

void node::add_child(int n) {
  if (n < n_) {
    if (left_ == nullptr) {
      left_ = make_unique<node>(n);
    } else {
      left_->add_child(n);
    }
  } else {
    if (right_ == nullptr) {
      right_ = make_unique<node>(n);
    } else {
      right_->add_child(n);
    }
  }
}

void postorder(node* root) {
  if (root == nullptr) {
    return;
  }
  postorder(root->get_left());
  postorder(root->get_right());
  cout << root->get_n() << "\n";
}

int main() {
  int n;
  unique_ptr<node> root = nullptr;

  init();

  while ((cin >> n).get() != EOF) {
    if (root == nullptr) {
      root = make_unique<node>(n);
    } else {
      root->add_child(n);
    }
  }

  postorder(root.get());

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}