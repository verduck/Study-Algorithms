#include <iostream>
#include <vector>

using namespace std;

void init();

int fn(vector<int>& memo, int n) {
  if (memo[n - 1]) {
    return memo[n - 1];
  } else {
    return memo[n - 1] = fn(memo, n - 1) + fn(memo, n - 2) + fn(memo, n - 3);
  }

}

int main() {
  int t;
  vector<int> memo(11, 0);

  init();

  memo[0] = 1;
  memo[1] = 2;
  memo[2] = 4;

  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    cout << fn(memo, n) << '\n';
  }

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}