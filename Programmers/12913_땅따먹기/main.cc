#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;

    for (int i = 1; i < land.size(); i++) {
        land[i][0] = max(land[i][0] + land[i - 1][1], max(land[i][0] + land[i - 1][2], land[i][0] + land[i - 1][3]));
        land[i][1] = max(land[i][1] + land[i - 1][0], max(land[i][1] + land[i - 1][2], land[i][1] + land[i - 1][3]));
        land[i][2] = max(land[i][2] + land[i - 1][0], max(land[i][2] + land[i - 1][1], land[i][2] + land[i - 1][3]));
        land[i][3] = max(land[i][3] + land[i - 1][0], max(land[i][3] + land[i - 1][1], land[i][3] + land[i - 1][2]));
    }

    answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());

    return answer;
}

int main() {
    vector<vector<int>> land = { { 1, 2, 3, 5 }, { 5, 6, 7, 8 }, { 4, 3, 2, 1 } };
    int result = solution(land);
    cout << result << '\n';
    return 0;
}