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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(),nums.end());
        ListNode* d=new ListNode(0);
        d->next=head;
        ListNode*p=d;
       
        while(p->next!=NULL){
            if(s.find(p->next->val)!=s.end()){
                p->next=p->next->next;
            }
            else p=p->next;

        }
        return d->next;
    }
};
