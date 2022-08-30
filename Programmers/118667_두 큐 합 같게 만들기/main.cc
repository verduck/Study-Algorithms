#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    long l = 0;
    long r = 0;
    long sum;
    for (int i : queue1) {
        l += i;
        q1.push(i);
    }

    for (int i : queue2) {
        r += i;
        q2.push(i);
    }
    
    sum = (l + r) / 2;
    while (!q1.empty() && !q2.empty() && l != r) {
        if (l > r) {
            int t = q1.front();
            q1.pop();
            l -= t;
            r += t;
            q2.push(t);
        } else if (l < r) {
            int t = q2.front();
            q2.pop();
            r -= t;
            l += t;
            q1.push(t);
        }
        if (++answer > queue1.size() * 4) {
            break;
        }
    }

    if (l != r) {
        return -1;
    }

    return answer;
}

int main() {
    vector<int> queue1 = { 3, 2, 7, 2 };
    vector<int> queue2 = { 4, 6, 5, 1 };
    int result = solution(queue1, queue2);
    cout << result << '\n';
    return 0;
}