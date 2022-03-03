#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        answer += d[i];
        if (answer > budget) {
            return i;
        }
    }
    return d.size();
}

int main(void) {
    vector<int> d = { 2, 2, 3, 3 };
    int budget = 10;
    int answer = solution(d, budget);
    cout << answer << '\n';
    return 0;
}