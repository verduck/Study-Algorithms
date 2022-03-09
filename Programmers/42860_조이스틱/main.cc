#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.size();
    int move = length - 1;

    for (int i = 0; i < length; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        int index = i + 1;
        while (index < length && name[index] == 'A') {
            index++;
        }

        move = min(move, min(i * 2 + length - index, (length - index) * 2 + i));
    }

    return answer;
}

/* int solution(string name) {
    int answer = 0;
    string s(name.size(), 'A');
    int move = 0;
    int pos = 0;

    while (pos != -1) {
        answer += move;
        move = min(name[pos] - s[pos], 'Z' - name[pos] + 1);
        answer += move;
        s[pos] = name[pos];
        name[pos] = 'A';

        int right_pos = name.find_first_not_of('A');
        int left_pos = name.find_last_not_of('A');
        int right = min(abs(right_pos - pos), abs(static_cast<int>(s.size()) - right_pos) + pos);
        int left = min(abs(left_pos - pos), abs(static_cast<int>(s.size()) - left_pos) + pos);

        if (right <= left) {
            move = right;
            pos = right_pos;
        } else {
            move = left;
            pos = left_pos;
        }
    }
    return answer;
} */

int main() { 
    string name = "BBBBAAAAB";
    int answer = solution(name);
    cout << answer << '\n';
    return 0;
}