#include <iostream>
#include <vector>

using namespace std;

void init();
int fib(int* c, int n);
int fibonacci(int* c, int n);

int main() {
  int n;
  int c1 = 0, c2 = 0;

  init();
  
  cin >> n;

  fib(&c1, n);
  c1++;
  fibonacci(&c2, n);

  cout << c1 << ' ' << c2 << '\n';

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int fib(int* c, int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    (*c)++;
    return (fib(c, n - 1) + fib(c, n - 2));
  }
}

int fibonacci(int* c, int n) {
  vector<int> f(n + 1, 0);
  f[1] = f[2] = 1;
  for (int i = 3; i <= n; i++) {
    (*c)++;
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}