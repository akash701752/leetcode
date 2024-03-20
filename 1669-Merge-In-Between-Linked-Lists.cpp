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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1 , *prev = list1 ;
        int count = 0 ;
        while(temp!=NULL){
            if(count == a){
                break;
            }
            count++;
            prev = temp ;
            temp = temp->next;
        }
        //cout<<"prev = "<<prev->val <<endl;
        prev->next = list2 ;
        
        ListNode *t = list2 , *p = list2 ;
        while(t !=NULL){
            p = t;
            t = t->next;
        }
        ListNode* pp = NULL ;
        while(temp != NULL ){
            if(count == b){
                break ;
            }
            count++;
            //pp = temp ;
            temp = temp->next ;
        }
        if(temp!=NULL){
            p->next = temp->next;
        }
        else{
            p->next = NULL;
        }
        return list1;
    }
};
