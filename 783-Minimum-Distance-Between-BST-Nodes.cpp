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
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==NULL){
            return ;
        }
        inorder(root->left,v) ;
        v.push_back(root->val) ;
        inorder(root->right,v) ;
    }
    int minDiffInBST(TreeNode* root) {
        int mn = INT_MAX ;
        if(root==NULL){
            return mn ;
        }
        vector<int> v ;
        inorder(root,v) ;
        int i , n = v.size() ;
        for(i=1;i<n;i++){
            mn = min(mn,v[i]-v[i-1]) ;
        }
        return mn ;
    }
};
