#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq(scoville.begin(), scoville.end());

    while (pq.size() > 1) {
        int m = pq.top();
        pq.pop();
        int n = pq.top();
        pq.pop();
        int mix = m + (n * 2);
        pq.push(mix);
        answer++;
        if (pq.top() >= K) {
            return answer;
        }
    }

    answer = -1;

    return answer;
}

int main() { 
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 7;
    int result = solution(scoville, K);
    cout << result << '\n';
    return 0;
}