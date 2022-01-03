#include <iostream>
#include <vector>
#include <string>

using namespace std;

void init();

vector<int> get_pi(string grope) {
  int j = 0, len = static_cast<int>(grope.size());
  vector<int> pi(len, 0);
  for (int i = 1; i < len; i++) {
    while (j > 0 && grope[i] != grope[j]) {
      j = pi[j - 1];
    }
    if (grope[i] == grope[j]) {
      pi[i] = ++j;
    }
  }

  return pi;
}

vector<int> kmp(string t, string p) {
  vector<int> result;
  vector<int> pi = get_pi(p);
  int n = static_cast<int>(t.size());
  int m = static_cast<int>(p.size());
  int j = 0;

  for (int i = 0; i < n; i++) {
    while (j > 0 && t[i] != p[j]) {
      j = pi[j - 1];
    }
    if (t[i] == p[j]) {
      if (j == m - 1) {
        result.push_back(i - m + 1);
        j = pi[j];
      } else {
        j++;
      }
    } else {
      j = 0;
    }
  }

  return result;
}

int main() {
  string t, p;

  init();

  getline(cin, t);
  getline(cin, p);

  vector<int> result = kmp(t, p);

  cout << result.size() << "\n";
  for (int i : result) {
    cout << i + 1 << " ";
  }
  cout << "\n";

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}