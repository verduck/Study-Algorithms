#include <iostream>
#include <vector>

using namespace std;

bool is_prime_num(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            return false;
        }
    }

    return true;
}

void dfs(const vector<int>& nums, vector<bool>& visited, vector<int>& prime_nums, int index, int num, int depth) {
    if (depth == 3) {
        if (is_prime_num(num)) {
            prime_nums.push_back(num);
        }
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(nums, visited, prime_nums, i + 1, num + nums[i], depth + 1);
            visited[i] = false;
        }
    }
}

int solution(vector<int> nums) {
    int answer = -1;
    vector<int> prime_nums;
    vector<bool> visited(nums.size(), false);
    dfs(nums, visited, prime_nums, 0, 0, 0);
    answer = prime_nums.size();
    return answer;
}

int main() {
    vector<int> nums = { 1, 2, 7, 6, 4 };
    int result = solution(nums);
    cout << result << '\n';
    return 0;
}