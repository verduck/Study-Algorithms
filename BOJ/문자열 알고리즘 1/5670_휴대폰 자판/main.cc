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
  bool find(const string& s, int* skip, int i = 0);
private:
  vector<unique_ptr<trie>> children_;
  int count_of_children_;
  bool end_;
};

trie::trie() :
  children_(26),
  count_of_children_(0),
  end_(false) {}

void trie::insert(const string& s, int i) {
  if (s.size() <= i) {
    end_ = true;
    return;
  }
  int j = s[i] - 'a';
  if (children_[j] == nullptr) {
    children_[j] = make_unique<trie>();
    count_of_children_++;
  }
  children_[j]->insert(s, i + 1);
}

bool trie::find(const string& s, int* skip, int i) {
  if (s.size() <= i) {
    if (end_) {
      return true;
    } else {
      return false;
    }
  }
  int j = s[i] - 'a';
  if (children_[j] == nullptr) {
    return false;
  }
  if (count_of_children_ > 1 || end_ || i == 0) {
    (*skip)++;
  }
  return children_[j]->find(s, skip, i + 1);
}

int main() {
  int n;
  init();

  while ((cin >> n).get() != EOF) {
    vector<string> v;
    trie root;
    double answer = 0;

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      v.push_back(s);
      root.insert(s);
    }

    for (const string& s : v) {
      int skip = 0;
      root.find(s, &skip);
      answer += skip;
    }

    cout << answer / static_cast<double>(n) << "\n";
  }

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(2);
}