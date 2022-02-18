#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            int n = 0;
            for (int k = 0; k < arr2.size(); k++) {
                n += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = n;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> arr1 = { { 1, 4 }, { 3, 2 }, { 4, 1 } };
    vector<vector<int>> arr2 = { { 3, 3 }, { 3, 3 } };
    vector<vector<int>> result = solution(arr1, arr2);

    for (const vector<int>& v : result) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}