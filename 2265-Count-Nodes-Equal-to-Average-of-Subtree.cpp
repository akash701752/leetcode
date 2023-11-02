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
private:
    int count = 0;
public:
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        auto ls = solve(root->left);
        auto rs = solve(root->right);
        int sum = root->val + ls.first + rs.first;
        int nodes = ls.second + rs.second + 1;
        int avg = -1;
        if(nodes != 0) avg = sum/nodes;
        if(avg == root->val) count++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};
