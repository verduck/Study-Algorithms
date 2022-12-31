#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    int m = 0;
    for (int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);

        if (pq.size() > k) {
            m += pq.top();
            pq.pop();
        }

        if (m > n) {
            return i;
        }
    }

    return enemy.size();
}

int main() {
    int n = 2;
    int k = 4;
    vector<int> enemy = { 4, 2, 4, 5, 3, 3, 1 };
    
    int result = solution(n, k, enemy);
    cout << result << '\n';
    return 0;
}