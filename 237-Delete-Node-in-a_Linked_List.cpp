/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode *temp = node ;
        ListNode *prev ;
        while(temp->next!=NULL)
        {
            int t = (temp->next)->val ;
            temp->val = t ;
            prev = temp ;
            temp = temp->next ;
        }
        prev->next = NULL ;
    }
};
