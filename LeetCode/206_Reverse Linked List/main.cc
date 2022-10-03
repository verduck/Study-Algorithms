#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* result = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return result;
    }
};

void init();

int main() {
    ListNode* head = new ListNode(5, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(1)))));

    init();

    Solution solution;
    ListNode* result = solution.reverseList(head);

    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }

    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}