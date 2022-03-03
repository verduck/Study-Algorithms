#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<bool>> map1;
    vector<vector<bool>> map2;

    for (int i : arr1) {
        deque<bool> binary;
        while (i) {
            binary.push_front(i % 2);
            i /= 2;
        }

        while (binary.size() < n) {
            binary.push_front(0);
        }

        map1.push_back(vector<bool>(binary.begin(), binary.end()));
    }

    for (int i : arr2) {
        deque<bool> binary;
        while (i) {
            binary.push_front(i % 2);
            i /= 2;
        }

        while (binary.size() < n) {
            binary.push_front(0);
        }

        map2.push_back(vector<bool>(binary.begin(), binary.end()));
    }

    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < n; j++) {
            bool b = map1[i][j] | map2[i][j];
            if (b) {
                s += '#';
            } else {
                s += ' ';
            }
        }
        answer.push_back(s);
    }

    return answer;
}

int main(void) {
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    vector<string> answer = solution(n, arr1, arr2);
    for (const string& s : answer) {
        cout << s << '\n';
    }
    return 0;
}