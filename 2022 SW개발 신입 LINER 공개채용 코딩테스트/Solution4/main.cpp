#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, vector<int> brr) {
    int answer = 0;

    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] != brr[i]) {
            answer++;
            int diff = brr[i] - arr[i];
            arr[i] += diff;
            arr[i + 1] -= diff;
        }
    }

    return answer;
}

int main() {
    vector<int> arr = { 3, 7, 2, 4 };
    vector<int> brr = { 4, 5, 5, 2 };
    int result = solution(arr, brr);
    cout << result << '\n';
	return 0;
}