#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> v(10);
    vector<int> diff;

    sort(numbers.begin(), numbers.end());
    iota(v.begin(), v.end(), 0);
    set_difference(v.begin(), v.end(), numbers.begin(), numbers.end(), inserter(diff, diff.begin()));
    answer = accumulate(diff.begin(), diff.end(), 0);

    return answer;
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 6, 7, 8, 0 };
    int answer = solution(numbers);
    cout << answer << '\n';
    return 0;
}