#include <iostream>
#include <vector>
#include <string>
using namespace std;

void init();

void find_depth(const vector<vector<int>>& tree, vector<bool>& visited, vector<int>& parents, vector<int>& depths, int cur, int depth) {
  visited[cur] = true;
  depths[cur] = depth;
  for (int n : tree[cur]) {
    if (!visited[n]) {
      parents[n] = cur;
      find_depth(tree, visited, parents, depths, n, depth + 1);
    }
  }
}

int LCA(const vector<int>& parents, const vector<int>& depths, int a, int b) {
  while (depths[a] != depths[b]) {
    if (depths[a] > depths[b]) {
      a = parents[a];
    } else {
      b = parents[b];
    }
  }
  while (a != b) {
    a = parents[a];
    b = parents[b];
  }

  return a;
}

int main() {
  int t;
  

  init();

  cin >> t;
  while (t--) {
    vector<vector<int>> tree;
    vector<bool> visited;
    vector<int> parents;
    vector<int> depths;
    vector<bool> roots;
    int n;
    cin >> n;
    tree.assign(n, vector<int>());
    visited.assign(n, false);
    parents.assign(n, 0);
    depths.assign(n, 0);
    roots.assign(n, true);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      tree[a - 1].push_back(b - 1);
      roots[b - 1] = false;

    }
    int answer = 0;
    int a, b;
    cin >> a >> b;

    int s = 0;

    for (int i = 0; i < roots.size(); i++) {
      if (roots[i]) {
        s = i;
      }
    }

    find_depth(tree, visited, parents, depths, s, 0);

    answer = LCA(parents, depths, a - 1, b - 1);
    cout << answer + 1 << "\n";
  }
  
  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}