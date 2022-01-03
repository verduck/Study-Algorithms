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

int main() {
  string s;

  init();

  while (true) {
    int answer = 0;
    vector<int> pi;
    cin >> s;

    if (s == ".") {
      break;
    }

    pi = get_pi(s);
    if (s.size() % (s.size() - pi[s.size() - 1]) != 0) {
      cout << 1 << "\n";
    } else {
      cout << s.size() / (s.size() - pi[s.size() - 1]) << "\n";
    }
  }

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}