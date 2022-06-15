#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init();

bool is_in_squre(int x1, int y1, int x2, int y2, int px, int py);
double distance(int x1, int y1, int x2, int y2);

int main() {
  int w, h, x, y ,p;
  int answer = 0;

  init();

  cin >> w >> h >> x >> y >> p;

  int r = h / 2;
  for (int i = 0; i < p; i++) {
    int px, py;
    cin >> px >> py;

    if (is_in_squre(x, y, x + w, y + h, px, py)) {
      answer++;
    } else if (distance(x, y + r, px, py) <= r) {
      answer++;
    } else if (distance(x + w, y + r, px, py) <= r) {
      answer++;
    }
  }

  cout << answer << '\n';

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

bool is_in_squre(int x1, int y1, int x2, int y2, int px, int py) {
  if (x1 <= px && x2 >= px && y1 <= py && y2 >= py) {
    return true;
  } else {
    return false;
  }
}

double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}