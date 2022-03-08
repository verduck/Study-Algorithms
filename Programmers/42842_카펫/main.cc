#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    int width = 0;
    int height = 3;
    while (true) {
        int yellow_height = height - 2;
        int yellow_width = yellow / yellow_height;
        width = yellow_width + 2;
        if (width * 2 + yellow_height * 2 == brown && yellow_width * yellow_height == yellow) {
            break;
        }
        height++;
    }

    if (width >= height) {
        answer[0] = width;
        answer[1] = height;
    } else {
        answer[0] = height;
        answer[1] = width;
    }
    return answer;
}

int main() { 
    int brown = 10;
    int yellow = 2;
    vector<int> answer = solution(brown, yellow);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}