#include <iostream>
#include <string>
#include <vector>

using namespace std;

double ttod(const string& str) {
    double h = stod(str.substr(0, 2));
    double m = stod(str.substr(3, 2));
    double s = stod(str.substr(6, 6));

    return (h * 60 * 60) + (m * 60) + s;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double, double>> logs;

    for (const string& s : lines) {
        double end = ttod(s.substr(11, 12));
        double proccessing_time = stod(s.substr(24, 5));
        double start = end - proccessing_time + 0.001;
        logs.push_back({ start, end });
    }

    for (int i = 0; i < logs.size(); i++) {
        int count = 0;
        for (int j = i; j < logs.size(); j++) {
            if (logs[i].second > logs[j].first - 1) {
                count++;
            }
        }
        answer = max(answer, count);
    }
    return answer;
}

int main(void) {
    vector<string> lines = { "2016-09-15 20:59:57.421 0.351s",
                            "2016-09-15 20:59:58.233 1.181s",
                            "2016-09-15 20:59:58.299 0.8s",
                            "2016-09-15 20:59:58.688 1.041s",
                            "2016-09-15 20:59:59.591 1.412s",
                            "2016-09-15 21:00:00.464 1.466s",
                            "2016-09-15 21:00:00.741 1.581s",
                            "2016-09-15 21:00:00.748 2.31s",
                            "2016-09-15 21:00:00.966 0.381s",
                            "2016-09-15 21:00:02.066 2.62s"
                            };
    int answer = solution(lines);
    cout << answer << '\n';
    return 0;
}