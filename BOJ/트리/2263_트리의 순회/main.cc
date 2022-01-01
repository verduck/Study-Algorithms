#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init();

void preorder(const vector<int>& inorder_list, const vector<int>& postorder_list, const vector<int>& inorder_indexes, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
  if (inorder_left > inorder_right || postorder_left > postorder_right) {
    return;
  }

  int n = postorder_list[postorder_right];
  int inorder_root_index = inorder_indexes[n];

  cout << n << " ";
  
  int il = inorder_left;
  int ir = inorder_root_index - 1;
  int pl = postorder_left;
  int pr = postorder_left + ir - il;
  preorder(inorder_list, postorder_list, inorder_indexes, il, ir, pl, pr);

  il = inorder_root_index + 1;
  ir = inorder_right;
  pl = pr + 1;
  pr = postorder_right - 1;
  preorder(inorder_list, postorder_list, inorder_indexes, il, ir, pl, pr);
}

int main() {
  int n;
  vector<int> inorder_list;
  vector<int> postorder_list;
  vector<int> inorder_indexes;
  int root_num;

  init();
  
  cin >> n;
  inorder_list.assign(n, 0);
  postorder_list.assign(n, 0);
  inorder_indexes.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> inorder_list[i];
    inorder_indexes[inorder_list[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> postorder_list[i];
  }

  preorder(inorder_list, postorder_list, inorder_indexes, 0, n - 1, 0, n - 1);
  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}