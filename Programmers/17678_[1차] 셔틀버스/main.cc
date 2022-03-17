#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int ttoi(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    return h * 60 + m;
}

string titos(int t) {
    string h = to_string(t / 60);
    string m = to_string(t % 60);

    if (h.size() == 1) {
        h.insert(h.begin(), '0');
    }
    if (m.size() == 1) {
        m.insert(m.begin(), '0');
    }

    return h + ":" + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int time = 0;
    priority_queue<int, vector<int>, greater<>> waiting;
    int bustime = ttoi("09:00");

    for (const string& s : timetable) {
        waiting.push(ttoi(s));
    }

    for (int i = 0; i < n; i++) {
        int geton = 0;
        int last = bustime;
        while (!waiting.empty() && geton < m) {
            last = waiting.top();
            if (last > bustime) {
                break;
            }
            waiting.pop();
            geton++;
        }

        if (geton < m) {
            time = bustime;
        } else {
            time = last - 1;
        }
        bustime += t;
    }

    answer = titos(time);

    return answer;
}

int main(void) {
    int n = 2;
    int t = 10;
    int m = 2;
    vector<string> timetable = { "09:10", "09:09", "08:00" };
    string answer = solution(n, t, m, timetable);
    cout << answer << '\n';
    return 0;
}