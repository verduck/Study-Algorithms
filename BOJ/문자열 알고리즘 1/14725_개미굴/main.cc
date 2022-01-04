#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void init();

class anthill {
public:
  anthill();
  anthill(const string& name, int depth);
  void add_child(const vector<string>& v, int i = 0);
  void print_info();
private:
  string name_;
  int depth_;
  map<string, anthill> childs_;
};

anthill::anthill() :
  anthill(string(), -1) {}

anthill::anthill(const string& name, int depth) :
  name_(name),
  depth_(depth) {}

void anthill::add_child(const vector<string>& v, int i) {
  if (v.size() == i) {
    return;
  }
  string name = v[i];
  auto it = childs_.find(name);
  if (it == childs_.end()) {
    childs_.emplace(name, anthill(name, depth_ + 1));
    childs_[name].add_child(v, i + 1);
  } else {
    childs_[name].add_child(v, i + 1);
  }
}

void anthill::print_info() {
  if (depth_ != -1) {
    for (int i = 0; i < depth_; i++) {
      cout << "--";
    }
    cout << name_ << "\n";
  }
  for (auto it = childs_.begin(); it != childs_.end(); it++) {
    it->second.print_info();
  }
}


int main() {
  int n;
  anthill ant;

  init();

  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    vector<string> v;
    cin >> k;
    for (int j = 0; j < k; j++) {
      string s;
      cin >> s;
      v.push_back(s);
    }
    ant.add_child(v);
  }

  ant.print_info();

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}