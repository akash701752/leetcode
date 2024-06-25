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
    int prefixSum = 0;
    public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }

    void traverse(TreeNode* node){
        if (!node){
            return;
        }

        traverse(node->right); 
        int tmp = node->val;
        node->val += prefixSum;
        prefixSum += tmp;
        traverse(node->left);
    }
};
