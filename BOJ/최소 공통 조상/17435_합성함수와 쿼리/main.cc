#include <iostream>
#include <vector>

using namespace std;

void init();

int main() {
  int m, q;
  vector<vector<int>> f;

  init();

  cin >> m;
  f.assign(m + 1, vector<int>(19, 0));

  for (int i = 1; i <= m; i++) {
    cin >> f[i][0];
  }

  for (int j = 1; j < 19; j++) {
    for (int i = 1; i <= m; i++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
  }

  cin >> q;
  while (q--) {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < 19; i++) {
      if (n & (1 << i)) {
        x = f[x][i];
      }
    }

    cout << x << "\n";

  }
  
  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}