#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

long long factorial(int n) {
    long long m = 1;
    for (int i = 1; i <= n; i++) {
        m *= i;
    }
    return m;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    long long f = factorial(v.size()); 

    while (f != 1) {
        long long m = f / v.size();
        int i = ceil(k / static_cast<double>(m)) - 1;
        answer.push_back(v[i]);
        k %= m;
        if (k == 0) k = m;
        f /= v.size();
        v.erase(v.begin() + i);
    }
    answer.push_back(v.front());

    return answer;
}



int main() {
    int n = 20;
    long long k = 22283;

    vector<int> result = solution(n, k);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}