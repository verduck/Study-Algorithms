#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> answer;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int stoti(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> in;
    map<string, int> fee;

    for (const string& s : records) {
        vector<string> info = split(s, ' ');

        if (info[2] == "IN") {
            in.insert({ info[1], stoti(info[0]) });
        } else {
            int in_time = in[info[1]];
            fee[info[1]] += stoti(info[0]) - in_time;
            in.erase(info[1]);
        }
    }

    for (auto it = in.begin(); it != in.end(); it++) {
        int in_time = in[it->first];
        fee[it->first] += stoti("23:59") - in_time;
    }

    for (auto it = fee.begin(); it != fee.end(); it++) {
        int fee = fees[1];
        if (it->second > fees[0]) {
            fee = fees[1] + ceil((it->second - fees[0]) / static_cast<double>(fees[2])) * fees[3];
        }
        answer.push_back(fee);
    }

    return answer;
}

int main() {
    vector<int> result = solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << "\n";
    
    return 0;
}