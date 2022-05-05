#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(priority_queue<int>& pq, long long ability, int k, long long* answer) {
    if (pq.size() < 2) {
        if (k > 0) {
            ability += pq.top();
        }

        *answer = max(*answer, ability);
        return;
    }

    int f = pq.top();
    pq.pop();
    int s = pq.top();
    pq.pop();

    if (k > 0) {
        dfs(pq, ability + f, k - 1, answer);
    }

    dfs(pq, ability + s, k, answer);
    pq.push(f);
    pq.push(s);
}

long long solution1(vector<int> abilities, int k) {
    long long answer = 0;
    priority_queue<int> pq(abilities.begin(), abilities.end());
    dfs(pq, 0L, k, &answer);

    return answer;
}


bool is_odd(int n) {
    return n % 2;
}

//¡¶√‚
long long solution2(vector<int> abilities, int k) {
    long long answer = 0;
    priority_queue<int> pq(abilities.begin(), abilities.end());
    int m = *min_element(abilities.begin(), abilities.end());

    m = is_odd(abilities.size()) ? m : 0;

    while (pq.size() > 1) {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();

        if (f != s && k > 0 && f - s > m) {
            answer += f;
            k--;
        } else {
            answer += s;
        }
    }

    if (!pq.empty() && k > 0) {
        answer += pq.top();
        pq.pop();
    }

    return answer;
}

int main() {
    vector<int> abilities = { 7, 6, 8, 9, 10 };
    int k = 1;
    long long result = solution1(abilities, k);
    cout << result << '\n';
	return 0;
}