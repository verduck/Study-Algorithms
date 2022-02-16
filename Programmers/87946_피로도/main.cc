#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());

    do {
        int count = 0;
        int fatigue = k;
        for (int i = 0; i < dungeons.size(); i++) {
            if (fatigue >= dungeons[i][0]) {
                fatigue -= dungeons[i][1];
                count++;
            } else {
                break;
            }
        }

        answer = max(answer, count);
    } while(next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons = { { 80, 20 }, { 50, 40 }, { 30, 10 } };
    int result = solution(k, dungeons);
    cout << result << '\n';
    return 0;
}