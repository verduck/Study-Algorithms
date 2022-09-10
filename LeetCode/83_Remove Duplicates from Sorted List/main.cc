#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return deleteDuplicates(head, -101);
    }

    ListNode* deleteDuplicates(ListNode* head, int prev) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->val == prev) {
            return deleteDuplicates(head->next, prev);
        } else {
            return new ListNode(head->val, deleteDuplicates(head->next, head->val));
        }
    }
};

void init();

int main() {
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    int target = 3;
    init();

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);
    
    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}