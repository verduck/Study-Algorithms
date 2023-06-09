#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<vector<int>> fatigue = {
    { 1, 1, 1 },
    { 5, 1, 1 },
    { 25, 5, 1 }
};

int get_mineral_num(const string& mineral) {
    if (mineral == "diamond") {
        return 0;
    } else if (mineral == "iron") {
        return 1;
    } else {
        return 2;
    }
}

bool has_pick(const vector<int>& picks) {
    return !all_of(picks.begin(), picks.end(), [](int i) {
         return i == 0;
    });
}

void get_min_fatigue(vector<int> picks, const vector<string>& minerals, int pick_index, int mineral_index, int count, int sum, int* answer) {
    if (mineral_index >= minerals.size()) {
        *answer = min(*answer, sum);
        return;
    }

    if (count > 0) {
        string mineral = minerals[mineral_index];
        int mineral_num = get_mineral_num(mineral);
        get_min_fatigue(picks, minerals, pick_index, mineral_index + 1, count - 1, sum + fatigue[pick_index][mineral_num], answer);
    } else if (!has_pick(picks)) {
        *answer = min(*answer, sum);
        return;
    } else {
        for (int i = 0; i < picks.size(); i++) {
            if (picks[i] == 0) {
                continue;
            }
            vector<int> copy_picks;
            copy(picks.begin(), picks.end(), back_inserter(copy_picks));
            copy_picks[i]--;
            get_min_fatigue(copy_picks, minerals, i, mineral_index, 5, sum, answer);
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 25 * minerals.size();
    
    get_min_fatigue(picks, minerals, 0, 0, 0, 0, &answer);

    return answer;
}

int main() {
    vector<int> picks = { 0, 1, 1 };
    vector<string> minerals = { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" };

    int result = solution(picks, minerals);

    cout << result << '\n';

    return 0;
}