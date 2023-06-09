#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class plan {
public:
    plan(string name, int start, int playtime)
        : name_(name), start_(start), playtime_(playtime) {}
    
    plan() : plan("", 0, 0) {}

    bool operator()(const plan& left, const plan& right) const {
        if (left.start_ == right.start_) {
            return left.name_ > right.name_;
        }

        return left.start_ > right.start_;
    }

    string name() const {
        return name_;
    }

    int start() const {
        return start_;
    }

    int playtime() const {
        return playtime_;
    }

    void set_playtime(int playtime) {
        playtime_ = playtime;
    }
private:
    string name_;
    int start_;
    int playtime_;
};

int time2minutes(const string& time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 5));

    return hour * 60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<plan, vector<plan>, plan> pq;
    stack<plan> wait;

    for (const vector<string>& v : plans) {
        string name = v[0];
        int start = time2minutes(v[1]);
        int playtime = stoi(v[2]);

        pq.push(plan(name, start, playtime));
    }

    while (!pq.empty()) {
        plan cur = pq.top();
        pq.pop();

        if (!wait.empty()) {
            plan prev = wait.top();
            wait.pop();
            int time = cur.start() - prev.start();

            if (time < prev.playtime()) {
                prev.set_playtime(prev.playtime() - time);
                wait.push(prev);
            } else {
                answer.push_back(prev.name());
                time -= prev.playtime();

                while (!wait.empty()) {
                    prev = wait.top();
                    wait.pop();

                    if (time < prev.playtime()) {
                        prev.set_playtime(prev.playtime() - time);
                        wait.push(prev);
                        break;
                    } else {
                        answer.push_back(prev.name());
                    }

                    time -= prev.playtime();
                }
            }
        }

        wait.push(cur);
    }

    while (!wait.empty()) {
        answer.push_back(wait.top().name());
        wait.pop();
    }

    return answer;
}

int main() {
    vector<vector<string>> plans = {
        { "science", "12:40", "50" },
        { "music", "12:20", "40" },
        { "history", "14:00", "30" },
        { "computer", "12:30", "100" }
    };

    vector<string> result = solution(plans);

    for (const string& s : result) {
        cout << s << '\n';
    }

    return 0;
}