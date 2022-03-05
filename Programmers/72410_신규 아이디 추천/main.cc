#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    for (auto it = new_id.begin(); it != new_id.end();) {
        if (!isalnum(*it) && *it != '-' && *it != '_' && *it != '.') {
            it = new_id.erase(it);
        } else {
            it++;
        }
    }

    for (auto it = new_id.begin(); it != new_id.end();) {
        if (*it == '.') {
            while (++it != new_id.end() && *it == '.') {
                it-- = new_id.erase(it);
            }
        } else {
            it++;
        }
    }

    auto it = new_id.begin();
    if (*it == '.') {
        it = new_id.erase(it);
    }
    it = new_id.end() - 1;
    if (*it == '.') {
        it = new_id.erase(it);
    }

    if (new_id.empty()) {
        new_id = "a";
    }

    if (new_id.size() >= 16) {
        new_id = new_id.substr(0, 15);
        it = new_id.end() - 1;
        if (*it == '.') {
            it = new_id.erase(it);
        }
    }
    
    answer = new_id;
    return answer;
}

int main() {
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    string answer = solution(new_id);
    cout << answer << '\n';
    return 0;
}