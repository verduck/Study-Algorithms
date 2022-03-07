#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    while (right - left > 0) {
        int light = people[left];
        int heavy = people[right];
        if (light + heavy <= limit) {
            left++;
            right--;
            answer++;
        } else {
            right--;
            answer++;
        }
    }

    if (left == right) {
        answer++;
    }

    return answer;
}

int main() { 
    vector<int> people = { 70, 50, 80, 50 };
    int limit = 100;
    int answer = solution(people, limit);
    cout << answer << '\n';
    return 0;
}