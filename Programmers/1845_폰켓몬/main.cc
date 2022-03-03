#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int can = nums.size() / 2;
    set<int> phonecketmon(nums.begin(), nums.end());

    if (phonecketmon.size() < can) {
        answer = phonecketmon.size();
    } else {
        answer = can;
    }

    return answer;
}

int main() {
    vector<int> nums = { 3, 3, 3, 2, 2, 4 };
    int answer = solution(nums);
    cout << answer << '\n';
    return 0;
}