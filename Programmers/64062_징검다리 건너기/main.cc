#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& stones, int k, int m) {
    int p = 0;
    for (int i : stones) {
        if (i < m) {
            p++;
        } else {
            p = 0;
        }

        if (p == k) {
            return false;
        }
    }

    return true;
} 

int solution(vector<int> stones, int k) {
    int answer = 0;
    if (k == 1) {
        return *min_element(stones.begin(), stones.end());
    }

    int left = 0;
    int right = *max_element(stones.begin(), stones.end());

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(stones, k, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    answer = left - 1;
    return answer;
}

int main() {
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 3;
    int answer = solution(stones, k);
    cout << answer << '\n';
    return 0;
}