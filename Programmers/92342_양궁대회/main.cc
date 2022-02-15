#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> temp;
int g_max = 0;

void dfs(int n, const vector<int>& info, vector<int>& answer, int index) {
    if (n == 0) {
        int apeach = 0;
        int lion = 0;
        for (int i = 0; i < info.size(); i++) {
            int score = 10 - i;
            if (info[i] > temp[i]) {
                apeach += score;
            } else if (info[i] < temp[i]) {
                lion += score;
            }
        }
        if (lion > apeach) {
            int diff = lion - apeach;
            if (diff == g_max) {
                for (int i = answer.size() - 1; i >= 0; i--) {
                    if (temp[i] > answer[i]) {
                        answer = temp;
                        break;
                    } else if (answer[i] > temp[i]) {
                        break;
                    }
                }
                
            } else if (diff > g_max) {
                g_max = diff;
                answer = temp;
            }
        }
        return;
    }

    for (int i = index; i < info.size(); i++) {
        if (n > info[i]) {
            temp[i] = info[i] + 1;
            dfs(n - temp[i], info, answer, i + 1);
            temp[i] = 0;
        } else {
            if (i == info.size() - 1) {
                temp[i] = n;
                dfs(0, info, answer, i + 1);
                temp[i] = 0;
            } else {
                dfs(0, info, answer, i + 1);
            }
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(info.size(), 0);
    temp.assign(info.size(), 0);

    dfs(n, info, answer, 0);

    int sum = accumulate(answer.begin(), answer.end(), 0);
    if (sum == 0) {
        answer = { -1 };
    }

    return answer;
}

int main() {
    int n = 10;
    vector<int> info = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3};
    vector<int> result = solution(n, info);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}