#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    long long left = times[0];
    long long right = static_cast<long long>(times[times.size() - 1]) * n;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long people = 0;
        for (int t : times) {
            people += mid / t;
            if (people >= n) {
                break;
            }
        }

        if (people >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() { 
    int n = 6;
    vector<int> times = { 7, 10 };
    long long result = solution(n, times);
    cout << result << '\n';
    return 0;
}