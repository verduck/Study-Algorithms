#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> direction = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
};

void clock(vector<vector<int>>& arr, bool clockwise, int x, int y, int n, int d, int size) {
    if (size == 0 || size == 1) {
        arr[y][x] = n++;
        return;
    }

    for (int i = 0; i < size; i++) {
        arr[y][x] = n++;
        if (i == size - 1) {
            if (clockwise) {
                d = (d + 1) % direction.size();
            } else {
                d = (d + 3) % direction.size();
            }
        }
        x += direction[d].first;
        y += direction[d].second;
    }

    clock(arr, clockwise, x, y, n, d, size - 2);
}

vector<vector<int>> solution(int n, bool clockwise) {
    vector<vector<int>> answer(n, vector<int>(n, 0));

    if (clockwise) {
        clock(answer, clockwise, 0, 0, 1, 1, n - 1);
        clock(answer, clockwise, n - 1, 0, 1, 2, n - 1);
        clock(answer, clockwise, n - 1, n - 1, 1, 3, n - 1);
        clock(answer, clockwise, 0, n - 1, 1, 0, n - 1);
    } else {
        clock(answer, clockwise, 0, 0, 1, 2, n - 1);
        clock(answer, clockwise, n - 1, 0, 1, 3, n - 1);
        clock(answer, clockwise, n - 1, n - 1, 1, 0, n - 1);
        clock(answer, clockwise, 0, n - 1, 1, 1, n - 1);
    }

    return answer;
}

int main() {
	int n = 9;
	bool clockwise = false;
	vector<vector<int>> result = solution(n, clockwise);
	for (const vector<int>& v : result) {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}