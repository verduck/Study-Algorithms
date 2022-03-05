#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    vector<int> rank = { 6, 6, 5, 4, 3, 2, 1 };
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    vector<int> intersection;
    set_intersection(lottos.begin(), lottos.end(), win_nums.begin(), win_nums.end(), inserter(intersection, intersection.begin()));

    int zero_count = count(lottos.begin(), lottos.end(), 0);
    answer[0] = rank[intersection.size() + zero_count];
    answer[1] = rank[intersection.size()];
    return answer;
}

int main() {
    vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
    vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
    vector<int> answer = solution(lottos, win_nums);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}