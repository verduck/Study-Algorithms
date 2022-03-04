#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> get_coord(int n) {
    if (n == 0) {
        return { 1, 3 };
    }

    return { (n - 1) % 3, (n - 1) / 3 };
}

int dist(const pair<int, int>& p1, const pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left_pos = { 0, 3 };
    pair<int, int> right_pos = { 2, 3 };

    for (int i : numbers) {
        pair<int, int> coord = get_coord(i);
        if (i % 3 == 1) {
            left_pos = coord;
            answer += 'L';
        } else if (i != 0 && i % 3 == 0) {
            right_pos = coord;
            answer += 'R';
        } else {
            int left_dist = dist(coord, left_pos);
            int right_dist = dist(coord, right_pos);
            if (left_dist < right_dist) {
                left_pos = coord;
                answer += 'L';
            } else if (left_dist > right_dist) {
                right_pos = coord;
                answer += 'R';
            } else {
                if (hand == "left") {
                    left_pos = coord;
                    answer += 'L';
                } else {
                    right_pos = coord;
                    answer += 'R';
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    string hand = "right";
    string answer = solution(numbers, hand);
    cout << answer << '\n';
    return 0;
}