#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> result;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    return result;
}

int ttoi(string s) {
    vector<string> time = split(s, ':');
    int h = stoi(time[0]);
    int m = stoi(time[1]);

    return h * 60 + m;
}

int get_play_time(const string& start_time, const string& end_time) {
    return ttoi(end_time) - ttoi(start_time);
}

string convert_sharp(string melody) {
    for (auto it = melody.begin(); it != melody.end();) {
        if (*it == '#') {
            auto prev = it - 1;
            *prev = tolower(*prev);
            it = melody.erase(it);
        } else {
            it++;
        }
    }
    return melody;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int max_time = 0;

    m = convert_sharp(m);

    for (const string& s : musicinfos) {
        vector<string> musicinfo = split(s, ',');
        int play_time = get_play_time(musicinfo[0], musicinfo[1]);
        string name = musicinfo[2];
        string melody = convert_sharp(musicinfo[3]);
        while (melody.size() < play_time) {
            melody += melody;
        }
        melody = melody.substr(0, play_time);
        if (melody.find(m) != string::npos && play_time > max_time) {
            answer = name;
            max_time = play_time;
        }
    }
    return answer;
}

int main() {
    string m = "CC#BCC#BCC#BCC#B";
    vector<string> musicinfos = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };
    string answer = solution(m, musicinfos);
    cout << answer << '\n';
    return 0;
}