#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

    do {
        bool ok = true;
        for (const string& s : data) {
            auto left_pos = find(friends.begin(), friends.end(), s[0]);
            auto right_pos = find(friends.begin(), friends.end(), s[2]);
            char comp_op = s[3];
            int comp_dist = s[4] - '0';
            int dist = abs(distance(left_pos, right_pos)) - 1;
            if (comp_op == '=') {
                ok = dist == comp_dist;
            } else if (comp_op == '<') {
                ok = dist < comp_dist;
            } else if (comp_op == '>') {
                ok = dist > comp_dist;
            }
            if (!ok) {
                break;
            }
        }

        if (ok) {
            answer++;
        }
    } while (next_permutation(friends.begin(), friends.end()));
    return answer;
}

int main() {
    int n = 2;
    vector<string> data = { "N~F=0", "R~T>2" };
    int answer = solution(n, data);
    cout << answer << '\n';
    return 0;
}