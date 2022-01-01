#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void init();

class disjoint_set {
public:
	disjoint_set();
	disjoint_set(int x);

	void assign(int x);
	int find_set(int x);
	bool union_set(int x, int y);
  std::vector<int> get_parent() const;
private:
	std::vector<int> parent_;
	std::vector<int> rank_;
};

disjoint_set::disjoint_set() :
	disjoint_set(0) {}

disjoint_set::disjoint_set(int x) :
	parent_(x), rank_(x, 0) {
	for (int i = 0; i < x; i++) {
		parent_[i] = i;
	}
}

void disjoint_set::assign(int x) {
	parent_.assign(x, 0);
	rank_.assign(x, 0);

	for (int i = 0; i < x; i++) {
		parent_[i] = i;
	}
}

int disjoint_set::find_set(int x) {
	if (x != parent_[x]) {
		return parent_[x] = find_set(parent_[x]);
	}

	return parent_[x];
}

bool disjoint_set::union_set(int x, int y) {
	x = find_set(x);
	y = find_set(y);

	if (x == y) {
		return true;
	}

	if (rank_[x] < rank_[y]) {
		parent_[x] = y;
	}
	else if (rank_[x] > rank_[y]) {
		parent_[y] = x;
	} else {
		parent_[y] = x;
		rank_[x] += 1;
	}

	return false;
}

vector<int> disjoint_set::get_parent() const {
  return parent_;
}

int main() {
  int c = 1;
  init();

  while (true) {
    disjoint_set ds;
    set<int> graph;
    int notree = 0;
    int n, m;

    cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }

    ds.assign(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      if (ds.union_set(a - 1, b - 1)) {
        graph.insert(ds.find_set(a - 1));
      }
    }

    vector<int> parent = ds.get_parent();
    set<int> tree(parent.begin(), parent.end());

    if (tree.size() - graph.size() == 0) {
      cout << "Case " << c << ": No trees.\n";
    } else if (tree.size() - graph.size() == 1) {
      cout << "Case " << c << ": There is one tree.\n";
    } else {
      cout << "Case " << c << ": A forest of " << tree.size() - graph.size() << " trees.\n";
    }
    c++;
  }

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}