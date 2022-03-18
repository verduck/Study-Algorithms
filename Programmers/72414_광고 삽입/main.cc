#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename ... Args>
string string_format(const string& format, Args ... args) {
    size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    if (size <= 0) { 
        throw runtime_error("Error during formatting.");
    }
    unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args ...);
    return string(buf.get(), buf.get() + size - 1);
}

string ittost(int i) {
    int s = i % 60;
    i -= s;
    int m = (i % 3600) / 60;
    int h = i / 3600;

    return string_format("%02d:%02d:%02d", h, m, s);
}

int sttoit(const string& str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int s = stoi(str.substr(6));

    return (h * 3600) + (m * 60) + s;
}

int accumulate(const vector<int>& memo, int play_time, int adv_time) {
    int result = 0;
    long long maxsum = 0;

    for (int i = 0; i < adv_time; i++) {
        maxsum += memo[i];
    }

    long long sum = maxsum;
    for (int i = adv_time; i < play_time; i++) {
        sum += memo[i] - memo[i - adv_time];

        if (sum > maxsum) {
            maxsum = sum;
            result = i - adv_time + 1;
        }
    }

    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int nplay_time = sttoit(play_time);
    int nadv_time = sttoit(adv_time);
    vector<int> memo(nplay_time + 1, 0);

    for (const string& s : logs) {
        int start = sttoit(s.substr(0, 8));
        int end = sttoit(s.substr(9));

        for (int i = start; i < end; i++) {
            memo[i]++;
        }
    }

    answer = ittost(accumulate(memo, nplay_time, nadv_time));
    
    return answer;
}

int main() {
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };
    string result = solution(play_time, adv_time, logs);
    cout << result << '\n';
    return 0;
}