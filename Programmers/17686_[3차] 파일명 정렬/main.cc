#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<string ,int> parse_part(const string& s) {
    string head;
    int number = 0;

    auto it = s.begin();
    for (it; it != s.end(); it++) {
        if (isdigit(*it)) {
            break;
        }
        head += tolower(*it);
    }

    for (it; it != s.end(); it++) {
        if (!isdigit(*it)) {
            break;
        }
        number *= 10;
        number += *it - '0';
    }
    return { head, number };
}

bool compare(const string& left, const string& right) {
    pair<string, int> left_part = parse_part(left);
    pair<string, int> right_part = parse_part(right);
    if (left_part.first == right_part.first) {
        return left_part.second < right_part.second;
    }
    return left_part.first < right_part.first;
}

vector<string> solution(vector<string> files) {
    vector<string> answer = files;
    stable_sort(answer.begin(), answer.end(), compare);
    return answer;
}

int main() {
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    vector<string> result = solution(files);
    for (const string& s : result) {
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}