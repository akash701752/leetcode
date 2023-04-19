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
        void traverse(TreeNode* root, bool isLeft, int length, int& maxLength) {
            if (root == nullptr) {
                return;
            }
            if (length > maxLength) {
                maxLength = length;
            }
            traverse(root->left, true, isLeft ? 1 : length + 1, maxLength);
            traverse(root->right, false, isLeft ? length + 1 : 1, maxLength);
        }
    
    public:
        int longestZigZag(TreeNode* root) {
            int maxLength = 0, maxLength2 = 0;
            traverse(root, true, 0, maxLength);
            return max(maxLength, maxLength2);
        }
};
