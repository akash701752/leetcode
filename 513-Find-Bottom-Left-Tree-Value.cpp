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
    int solve(TreeNode* node, int &height, TreeNode* parent){
        if(node==NULL){
            return parent->val;
        }
        int leftHeight = height+1 ;
        int rightHeight = height+1 ;

        int leftVal = solve(node->left,leftHeight, node);
        int rightVal = solve(node->right,rightHeight, node);

        if(rightHeight>leftHeight){
            height = rightHeight;
            return rightVal;
        }
        height = leftHeight;
        return leftVal;
    }
    int findBottomLeftValue(TreeNode* root) {
        int height = 0 ;
        int res = solve(root, height, NULL);
        return res;
    }
};
