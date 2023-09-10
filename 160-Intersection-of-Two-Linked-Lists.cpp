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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA , *t2 = headB;
        int l1 = 0 , l2 = 0 ;
        while(t1!=NULL || t2!=NULL){
            if(t1!=NULL){
                l1++;
                t1 = t1->next;
            }
            if(t2!=NULL){
                l2++;
                t2 = t2->next;
            }
        }
        int diff = abs(l1-l2);
        ListNode *temp ;
        if(l1>l2){
            temp = headA;    
        }
        else{
            temp = headB;
        }
        while(diff--){
            temp = temp->next;
        }
        ListNode *temp2 ;
        if(l1>l2){
            temp2 = headB;
        }
        else{
            temp2 = headA;
        }
        while(temp!=temp2 && temp!=NULL && temp2!=NULL){
            temp = temp->next;
            temp2 = temp2->next;
        }
        return temp;
    }
};
