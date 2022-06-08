#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

void init();

int main() {
  int n, m;
  unordered_set<int> us;

  init();

  cin >> n;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    us.insert(l);
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    int l;
    cin >> l;
    cout << (us.find(l) != us.end()) << ' ';
  }

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}