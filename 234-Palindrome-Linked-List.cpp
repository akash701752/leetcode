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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode *temp = head;
        while(temp!=NULL){
            st.push(temp);
            temp = temp->next;
        }
        temp = head ;
        bool flag = true;
        while(st.size()>0){
            ListNode *t = st.top();
            if(t->val!=temp->val){
                flag = false;
                break;
            }
            temp = temp->next ;
            st.pop();
        }
        return flag;
    }
};
