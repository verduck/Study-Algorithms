#include <iostream>
#include <vector>
#include <string>

using namespace std;

void init();

vector<int> get_pi(const vector<bool>& grope) {
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

bool kmp(const vector<bool>& t, const vector<bool>& p) {
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
        return true;
      } else {
        j++;
      }
    } else {
      j = 0;
    }
  }

  return false;
}

int main() {
  int n;
  vector<bool> t(720000, false);
  vector<bool> p(360000, false);

  init();

  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    t[a] = true;
    t[a + 360000] = true;
  }

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    p[a] = true;
  }

  bool result = kmp(t, p);
  if (result) {
    cout << "possible\n"; 
  } else {
    cout << "impossible\n";
  }
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}