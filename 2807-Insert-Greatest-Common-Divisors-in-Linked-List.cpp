/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (auto it = head; it->next; 
            it->next = new ListNode(gcd(it->val, it->next->val), it->next),
            it = it->next->next);
        return head;
    }
};
