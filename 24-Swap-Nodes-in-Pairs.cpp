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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode *prev , *temp , *t  , *s_prev;
        int c = 0 ;
        temp = head ;
        prev = head ;
        while(temp!=NULL)
        {
            c++ ;
            if(c%2==0) //for swapping
            {
                if(c==2) // for first node swapping
                {
                    t = temp->next ; // to store address of next node
                    head = temp ;
                    temp->next = prev ;
                    prev->next = t ;
                    s_prev = prev ;
                    temp = t ;
                }
                else
                {
                    t = temp->next ;
                    s_prev->next = temp ;
                    temp->next = prev ;
                    prev->next = t ;
                    s_prev = prev ;
                    temp = t ;
                }
            }
            else
            {
                prev = temp ;
                temp = temp->next ;
            }
            
        }
        return head ;
    }
};
