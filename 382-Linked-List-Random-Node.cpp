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
    ListNode *head ;
    Solution(ListNode* head) {
        this->head = head ;
    }
    
    int getRandom() {
        int count = 1;
        ListNode *temp = head , *res ;
        while(temp!=NULL)
        {
            if(rand()%count==0){
                res = temp;
            }
            temp = temp->next ;
            count++;
        }
        return res->val ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
