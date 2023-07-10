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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh = INT_MAX ;
        lh = 1+minDepth(root->left);
        int rh = 1+minDepth(root->right);
        if(lh==1){
            return rh ;
        }
        else if(rh==1){
            return lh ;
        }
        return min(lh,rh) ;
    }
};
