#include <iostream>
#include <vector>

using namespace std;

void init();

void dfs(const vector<vector<pair<int, int>>>& tree, vector<bool>& visited, int n, int dist, int* max_node, int* max_dist) {
  if (visited[n]) {
    return;
  }

  if (*max_dist < dist) {
    *max_dist = dist;
    *max_node = n;
  }

  visited[n] = true;
  for (const pair<int, int>& p : tree[n]) {
    dfs(tree, visited, p.first, dist + p.second, max_node, max_dist);
  }
}

int main() {
  int n;
  vector<vector<pair<int, int>>> tree;
  vector<bool> visited;

  init();
  
  cin >> n;
  tree.assign(n, vector<pair<int, int>>());
  visited.assign(n, false);

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    tree[a - 1].push_back({ b - 1, c });
    tree[b - 1].push_back({ a - 1, c });
  }

  int max_node = 0;
  int max_dist = 0;

  dfs(tree, visited, 0, 0, &max_node, &max_dist);
  visited.assign(n, false);
  max_dist = 0;

  dfs(tree, visited, max_node, 0, &max_node, &max_dist);

  cout << max_dist << "\n";

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}