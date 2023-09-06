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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL) ;
        ListNode* temp = head;;
        int count = 0 ;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        int step = count/k;
        int extra = count%k;
        int i = 0 ;
        while(i<extra && head!=NULL){
            ans[i] = head;
            for(int j=0;j<step; j++){
                head = head->next;
            }
            temp = head;
            head = head->next;
            temp->next = NULL;
            i++;
        }
        while(i<k && head!=NULL){
            ans[i] = head;
            for(int j=1;j<step; j++){
                head = head->next;
            }
            temp = head;
            head = head->next;
            temp->next = NULL;
            i++;
        }
        return ans;
    }
};
