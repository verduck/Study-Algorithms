#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total = 0;
    queue<pair<int, int>> bridge;

    for (int truck : truck_weights) {
        while (!bridge.empty() && (total + truck > weight || bridge.front().first + bridge_length == answer + 1)) {
            answer = bridge.front().first + bridge_length;
            total -= bridge.front().second;
            bridge.pop();
            answer--;
        }
        bridge.push({ ++answer, truck });
        total += truck;
    }
    
    while (!bridge.empty()) {
        pair<int, int> p = bridge.front();
        bridge.pop();
        answer = p.first + bridge_length;
    }
    
    return answer;
}

int main() {
    int bridge_length = 1;
    int weight = 2;
    vector<int> truck_weight = { 1, 1, 1 };
    int answer = solution(bridge_length, weight, truck_weight);
    cout << answer << '\n';
    return 0;
}