#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd_array(const vector<int>& v, int n, int i) {
    if (n == 1) {
        return v[i];
    } else if (n == 2) {
        return gcd(v[i], v[i + 1]);
    } else {
        return gcd(v[i], gcd_array(v, n - 1, i + 1));
    }
}

bool check(const vector<int>& v, int a) {
    for (int i : v) {
        if (i % a == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    int a = gcd_array(arrayA, arrayA.size(), 0);
    if (check(arrayB, a)) {
        answer = max(answer, a);
    }
    a = gcd_array(arrayB, arrayB.size(), 0);
    if (check(arrayA, a)) {
        answer = max(answer, a);
    }

    return answer;
}

int main() {
    vector<int> arrayA = { 10, 17 };
    vector<int> arrayB = { 5, 20 };
    int result = solution(arrayA, arrayB);
    cout << result << '\n';
    return 0;
}