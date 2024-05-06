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
    ListNode* removeNodes(ListNode* head) {
        stack <ListNode*> st;
        auto curr = head;
        head = new ListNode(INT_MAX, head);
        st.push(head);
        while(curr){
            while(st.top()->val<curr->val)
                st.pop();
            st.top()->next = curr;
            st.push(curr);
            curr = curr->next;
        }
        return head->next;
    }
};
