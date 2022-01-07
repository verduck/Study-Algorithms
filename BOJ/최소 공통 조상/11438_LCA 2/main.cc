#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void init();

void find_depth(const vector<vector<int>>& tree, vector<bool>& visited, vector<vector<int>>& parents, vector<int>& depths, int cur, int depth) {
  visited[cur] = true;
  depths[cur] = depth;
  for (int n : tree[cur]) {
    if (!visited[n]) {
      parents[n][0] = cur;
      find_depth(tree, visited, parents, depths, n, depth + 1);
    }
  }
}

void f(vector<vector<int>>& parents) {
  for (int j = 1; j < 18; j++) {
    for (int i = 0; i < parents.size(); i++) {
      parents[i][j] = parents[parents[i][j - 1]][j - 1];
    }
  }
}

int LCA(const vector<vector<int>>& parents, const vector<int>& depths, int a, int b) {
  if (depths[a] < depths[b]) {
    swap(a, b);
  }

  for (int i = 17; i >= 0; i--) {
    if (depths[a] - depths[b] >= (1 << i)) {
      a = parents[a][i];
    }
  }

  if (a == b) {
    return a;
  }

  for (int i = 17; i >= 0; i--) {
    if (parents[a][i] != parents[b][i]) {
      a = parents[a][i];
      b = parents[b][i];
    }
  }

  return parents[a][0];
}

int main() {
  vector<vector<int>> tree;
  vector<bool> visited;
  vector<vector<int>> parents;
  vector<int> depths;
  vector<bool> roots;
  int n, m, s = 0;

  init();

  cin >> n;
  tree.assign(n, vector<int>());
  visited.assign(n, false);
  parents.assign(n, vector<int>(20, 0));
  depths.assign(n, 0);
  roots.assign(n, true);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    tree[a - 1].push_back(b - 1);
    tree[b - 1].push_back(a - 1);
  }

  cin >> m;
  find_depth(tree, visited, parents, depths, 0, 0);
  f(parents);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    cout << LCA(parents, depths, a - 1, b - 1) + 1 << "\n";
  }
  
  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}