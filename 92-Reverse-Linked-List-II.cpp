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
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         stack<int> st;
//         ListNode* dummy = new ListNode(-1,head);
//         ListNode* temp , *l ,*r , *prev ;
//         temp = head;
//         if(temp==NULL){
//             return head;
//         }
//         int k = 0 ;
//         while(k<left-1){
//             //prev = temp;
//             temp = temp->next;
//             k++;
//         }
//         prev = temp ;
//         temp = temp->next;
//         while(k<right){
//             st.push(temp->val);
//             r = temp;
//             temp = temp->next;
//             k++;
//         }
//         while(st.size()>0){
//             prev->val = st.top();
//             prev = prev->next ;
//             st.pop();
//         }
//         //prev->next = temp ;
//         return head;
//     }
// };
class Solution {
public:
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // No need to reverse if left == right
        if(left == right) return head;
        
        // hold left to right values in stack 
        stack<int> stak;
        
        // track the left node pointer
        ListNode * prev = NULL;
        ListNode * thead = head;
        
        // loop till right and save values in stack from left to right
        // also save the left node pointer
        int i = 1;
        while(thead != NULL && i<=right)
        {
            if(i == left)
            {
                prev = thead;
            }
            
            if(i >= left && i <= right)
            {
                stak.push(thead->val);                
            }
            
            i++;
            thead = thead->next;
        }
        
        // loop through left pointer to right and set value from stack top
        int s = stak.size();
        for(int j=0;j<s;j++)
        {
            prev->val = stak.top();
            stak.pop();
            prev = prev->next;
        }
        
        return head;
            
    }
};
