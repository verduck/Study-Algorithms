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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->val != val) {
            return new ListNode(head->val, removeElements(head->next, val));
        } else {
            return removeElements(head->next, val);
        }
    }
};

void init();

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    int val = 6;

    init();

    Solution solution;
    ListNode* result = solution.removeElements(head, val);

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