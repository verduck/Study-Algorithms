#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

void init();

class trie {
public:
  trie();
  void insert(const string& s, int i = 0);
  bool find(const string& s, int i = 0);
private:
  vector<unique_ptr<trie>> childs_;
  bool end_;
};

trie::trie() :
  childs_(26),
  end_(false) {}

void trie::insert(const string& s, int i) {
  if (s.size() <= i) {
    end_ = true;
    return;
  }
  int j = s[i] - 'a';
  if (childs_[j] == nullptr) {
    childs_[j] = make_unique<trie>();
  }
  childs_[j]->insert(s, i + 1);
}

bool trie::find(const string& s, int i) {
  if (s.size() <= i) {
    if (end_) {
      return true;
    } else {
      return false;
    }
  }
  int j = s[i] - 'a';
  if (childs_[j] == nullptr) {
    return false;
  }
  return childs_[j]->find(s, i + 1);
}

int main() {
  int answer = 0;
  int n, m;
  trie trie;

  init();

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    trie.insert(s);
  }

  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (trie.find(s)) {
      answer++;
    }
  }

  cout << answer << "\n";

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}