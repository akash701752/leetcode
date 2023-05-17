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
    int pairSum(ListNode* head) {
        ListNode* p=head;

        vector<int>v;
        while(p->next!=NULL)
        {
            v.push_back(p->val);
            p=p->next;
        }
        v.push_back(p->val);
        int x=v.size();
        int i=0,j=x-1,sum=INT_MIN;
        while(i<j)
        {
            sum=max(sum,v[i]+v[j]);
            i++;
            j--;
        }
        return sum;
    }
};
