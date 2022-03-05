#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cmath>

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

int ttoi(string time) {
    vector<string> v = split(time, ':');
    int h = stoi(v[0]);
    int m = stoi(v[1]);

    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> total;
    unordered_map<string, int> in_time;

    for (const string& s : records) {
        vector<string> record = split(s, ' ');
        int time = ttoi(record[0]);
        string car_num = record[1];
        string history = record[2];

        if (history == "IN") {
            in_time[car_num] = time;
        } else {
            total[car_num] += time - in_time[car_num];
            in_time[car_num] = -1;
        }
    }

    for (auto it = in_time.begin(); it != in_time.end(); it++) {
        if (it->second != -1) {
            total[it->first] += ttoi("23:59") - it->second;
        }
    }

    for (auto it = total.begin(); it != total.end(); it++) {
        if (it->second <= fees[0]) {
            answer.push_back(fees[1]);
        } else {
            int fee = fees[1] + ceil(static_cast<double>(it->second - fees[0]) / fees[2]) * fees[3];
            answer.push_back(fee);
        }
    }

    return answer;
}

int main() {
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    vector<int> result = solution(fees, records);
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << "\n";
    
    return 0;
}