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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *t = new ListNode(-1) ;
        ListNode *res = t ;
        for(int i=0;i<lists.size();i++)
        {
            ListNode *temp = lists[i] ;
            while(temp!=NULL)
            {
                t->next = temp ;
                t = temp ;
                temp = temp->next ;
            }
        }
        ListNode *temp2 = res->next ;
        while(temp2!=NULL)
        {
            ListNode *temp3 = temp2->next ;
            while(temp3!=NULL)
            {
                if(temp2->val > temp3->val)
                {
                    swap(temp2->val,temp3->val) ;
                    temp3 =temp3->next ;
                }
                else
                {
                    temp3 =temp3->next ;
                }
            }
            temp2 = temp2->next ;
        }
        return (res->next) ;
    }
};
