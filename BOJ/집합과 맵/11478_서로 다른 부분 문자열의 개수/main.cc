#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void init();

int main() {
  string s;
  unordered_set<string> us;

  init();

  cin >> s;

  for (int i = 1; i <= s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      us.insert(s.substr(j, i));
    }
  }

  cout << us.size() << '\n';

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}