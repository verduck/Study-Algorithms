#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init();

double distance(int x1, int y1, int x2, int y2);

int main() {
  int t;

  init();

  cin >> t;

  while (t--) {
    int x1, y1, x2, y2;
    int n, count = 0;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int cx, cy, r;
      cin >> cx >> cy >> r;

      double dist1 = distance(x1, y1, cx, cy);
      double dist2 = distance(x2, y2, cx, cy);

      if (dist1 < r ^ dist2 < r) {
        count++;
      }
    }

    cout << count << '\n';

  }

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}