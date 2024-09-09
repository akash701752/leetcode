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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n,-1));
       
        int top=0,left=0,right=n-1,bottom=m-1;

        while(top<=bottom&&left<=right&&head){
            for(int j=left;j<=right&&head;j++){
                res[top][j] = head->val;
                head=head->next;
            }
            top++;
            for(int i=top;i<=bottom&&head;i++){
                res[i][right] = head->val;
                head=head->next;
            }
            right--;
            if(left<=right){
                for(int j=right;j>=left&&head;j--){
                    res[bottom][j] = head->val;
                    head=head->next;
                }
            }
            bottom--;
            if(top<=bottom){
                for(int i=bottom;i>=top&&head;i--){
                    res[i][left] = head->val;
                    head=head->next;
                }
            }
            left++;
        }
        return res;
    }
};
