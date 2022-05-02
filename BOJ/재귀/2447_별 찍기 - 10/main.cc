#include <iostream>
#include <vector>

using namespace std;

void init();
void draw_star(vector<vector<char>>& canvas, int size, int sx = 0, int sy = 0);

int main() {
  vector<vector<char>> canvas;
  int n;

  init();
  
  cin >> n;
  canvas.assign(n, vector<char>(n, ' '));

  draw_star(canvas, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << canvas[i][j];
    }
    cout << '\n';
  }

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void draw_star(vector<vector<char>>& canvas, int size, int sx, int sy) {
  if (size == 1) {
    canvas[sx][sy] = '*';
    return;
  }

  int div = size / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != 1 || j != 1) {
        draw_star(canvas, div, sx + (i * div), sy + (j * div));
      }
    }
  }
}