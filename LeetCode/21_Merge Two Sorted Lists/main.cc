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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        } else if (!list1) {
            return new ListNode(list2->val, mergeTwoLists(list1, list2->next));
        } else if (!list2) {
            return new ListNode(list1->val, mergeTwoLists(list1->next, list2));
        } else {
            if (list1->val < list2->val) {
                return new ListNode(list1->val, mergeTwoLists(list1->next, list2));
            } else {
                return new ListNode(list2->val, mergeTwoLists(list1, list2->next));
            }
        }
    }
};

void init();

int main() {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    init();

    Solution solution;
    ListNode* result = solution.mergeTwoLists(list1, list2);

    while (result) {
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