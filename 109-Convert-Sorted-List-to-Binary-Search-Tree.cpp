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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void insert(TreeNode* root, int x){
    //     if(root==NULL){
    //         root = new TreeNode(x) ;
    //         return ;
    //     }
    //     if(root->val<x){
    //         if(root->left==NULL){
    //             root->left = new TreeNode(x) ;
    //         }
    //         else{
    //             insert(root->left,x) ;
    //         }
    //     }
    //     else{
    //         if(root->right==NULL){
    //             root->right= new TreeNode(x) ;
    //         }
    //         else{
    //             insert(root->right,x) ;
    //         }
    //     }
    // }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return new TreeNode(head->val) ;
        }
        ListNode *slow, *fast ;
        slow = head , fast = head->next;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        ListNode *mid = slow->next ;
        slow->next = NULL ;
        TreeNode *root = new TreeNode(mid->val) ;
        root->left  = sortedListToBST(head) ;
        root->right = sortedListToBST(mid->next) ;
        return root ;
    }
};
