#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void init();

int main() {
  int a, b;
  set<int> a_set;
  set<int> b_set;

  init();

  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    int n;
    cin >> n;
    a_set.insert(n);
  }

  for (int i = 0; i < b; i++) {
    int n;
    cin >> n;
    b_set.insert(n);
  }

  vector<int> a_diff;
  vector<int> b_diff;
  set_difference(a_set.begin(), a_set.end(), b_set.begin(), b_set.end(), back_inserter(a_diff));
  set_difference(b_set.begin(), b_set.end(), a_set.begin(), a_set.end(), back_inserter(b_diff));

  cout << (a_diff.size() + b_diff.size()) << '\n';

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}