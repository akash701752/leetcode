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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *temp1 ,*temp2 ;
        temp1 = head ;
        temp2 = head ;
        int c = 0 ;
        while(temp1!=NULL)
        {
            c++ ;
            if(c==k)
                temp2 = temp1 ;
            temp1=temp1->next ;
        }
        int m = c-k ;
        if(m==0 &&c!=k)
            return head ;
        else
        {
            temp1 = head ;
            while(m>0)
            {
                temp1 = temp1->next ;
                m-- ;
            }
            int t= temp1->val ;
            temp1->val = temp2->val ;
            temp2->val = t ;
        }
        return head ;
    }
};
