#include <iostream>
#include <vector>

using namespace std;

void init();

int main() {
  int n, m;
  vector<int> v;

  init();

  cin >> n >> m;
  v.assign(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }

  for (int i : v) {
    cout << i << ' ';
  }

  for (int k = 0; k < m; k++) {
    int i, j;
    cin >> i >> j;
    cout << v[j] - v[i - 1] << '\n';
  }
  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}