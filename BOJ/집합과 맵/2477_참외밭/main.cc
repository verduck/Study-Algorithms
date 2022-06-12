#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init();

int main() {
  int k;
  vector<int> lengths;
  int max_width = 0;
  int max_width_index = 0;
  int max_height = 0;
  int max_height_index = 0;

  init();

  cin >> k;

  for (int i = 0; i < 6; i++) {
    int dir;
    int len;
    cin >> dir >> len;
    lengths.push_back(len);
    if (dir == 1 || dir == 2) {
      if (max_width < len) {
        max_width = len;
        max_width_index = i;
      }
    } else {
      if (max_height < len) {
        max_height = len;
        max_height_index = i;
      }
    }
  }
  int min_width = abs(lengths[(max_height_index + 1) % 6] - lengths[(max_height_index + 5) % 6]);
  int min_height = abs(lengths[(max_width_index + 1) % 6] - lengths[(max_width_index + 5) % 6]);
  int max_area = max_width * max_height;
  int min_area = min_width * min_height;

  cout << (max_area - min_area) * k << '\n';

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}