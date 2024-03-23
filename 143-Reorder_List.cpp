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
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL){
            return ;
        }
        //Using Stack
        stack<ListNode*> st ;
        int count = 0 , i ; // Node Count
        ListNode* temp = head;
        while(temp!=NULL){
            count++ ;
            st.push(temp) ;
            temp = temp->next ;
        }
        ListNode *current = head ;
        for(i=0;i<count/2;i++)
        {
            ListNode *stackNode  = st.top() ;
            st.pop() ;
            stackNode->next = current->next ;
            current->next   = stackNode ;
            current = (current->next)->next ;
        }
        current->next = NULL ;
    }
};
