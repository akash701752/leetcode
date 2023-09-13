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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head ;
        ListNode *next  ;
        if(head==NULL){
            return head ;
        }
        next = head ;
        while(next!=NULL){
            if(prev->val==next->val){
                prev->next = next->next ;
                next = next->next;
            }
            else{
                prev = next ;
                next = next->next;
            }
        }
        return head;
    }
};
