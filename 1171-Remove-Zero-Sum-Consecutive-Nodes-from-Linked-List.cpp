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
    ListNode* prno(ListNode* head,ListNode* nod){
        if(head==nod) return NULL;
        ListNode* cp=head;
        while(cp->next!=NULL && cp->next!=nod){
            cp=cp->next;
        }
        return cp;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* cp=head;
        while(cp!=NULL){
            ListNode* cp1=cp;
            int s=0,flag=1;
            while(cp1!=NULL){
                s+=cp1->val;
                if(s==0){
                    flag=0;
                    break;
                }
                cp1=cp1->next;
            }
            if(!flag){
                ListNode* p=prno(head,cp);
                if(p==NULL){
                    head=cp1->next;
                    cp=head;
                }
                else{
                    p->next=cp1->next;
                    cp=p;
                }
            }
            else{
            cp=cp->next;
            }
        }
        return head;
    }
};
