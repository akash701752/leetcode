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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
            return head;
        
        vector<ListNode*> smaller;
        vector<ListNode*> therest;
        ListNode* node = head;
        while(node)
        {
            if(node->val < x)
                smaller.push_back(node);
            else
                therest.push_back(node);
            node = node->next;
        }
        
        ListNode* newNode = new ListNode(0);
        ListNode* last=newNode;
        int i;
        for(i=0; i<smaller.size(); i++)
        {
            last->next = smaller[i];
            last = last->next;
        }
        for(i=0; i<therest.size(); i++)
        {
            last->next = therest[i];
            last = last->next;
        }
        last->next = NULL;
        
        return newNode->next;
    }
};
