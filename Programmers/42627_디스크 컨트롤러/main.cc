#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class compare {
public:
    bool operator() (const pair<int ,int>& left, const pair<int, int>& right) {
        if (left.second == right.second) {
            return left.first > right.first;
        }

        return left.second > right.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq_waitings;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq_jobs;

    for (const vector<int>& v : jobs) {
        pq_jobs.push({ v[0], v[1] });
    }

    int sec = 0;
    
    while (!pq_jobs.empty() || !pq_waitings.empty()) {
        while (!pq_jobs.empty() && pq_jobs.top().first <= sec) {
            pq_waitings.push(pq_jobs.top());
            pq_jobs.pop();
        }

        if (!pq_waitings.empty()) {
            auto job = pq_waitings.top();
            pq_waitings.pop();

            int waiting_time = sec - job.first;
            answer += waiting_time + job.second;
            sec += job.second;
        } else {
            sec = pq_jobs.top().first;
        }
    }
    return answer / jobs.size();
}

int main() {
    vector<vector<int>> jobs = { { 0, 3 }, { 1, 9 }, { 2, 6 } };
    int answer = solution(jobs);
    cout << answer << '\n';
    return 0;
}