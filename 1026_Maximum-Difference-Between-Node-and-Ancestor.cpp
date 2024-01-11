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
    int solve(TreeNode* root,int minVal,int maxVal){
        if(root==NULL){
            return maxVal-minVal ;
        }
        maxVal =  max(maxVal,root->val) ;
        minVal =  min(minVal,root->val) ;

        return max(solve(root->left,minVal,maxVal), solve(root->right,minVal,maxVal)) ;
    }
    int maxAncestorDiff(TreeNode* root) {
        int minVal = INT_MAX , maxVal = INT_MIN ;
        int ans = solve(root,minVal,maxVal) ;
        return ans ; 
    }
};
