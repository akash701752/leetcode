/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
        bool findpath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
            // find the path from target to root
            if (!root) {
                return false;
            }
            else if (root == target) {
                path.push_back(root);
                return true;
            }
            else {
                if (findpath(root->left, target, path) or findpath(root->right, target, path)) {
                    path.push_back(root);
                    return true;
                }
            }
            return false;
        }
    
    void findchildren(TreeNode* root, int h,unordered_set<TreeNode*>& visited, unordered_set<TreeNode*>& ans) {
        // find all children with height h under root, given root height = 0
        visited.insert(root);
        if (h == 0) {
            ans.insert(root);
        }
        else {
            if (root->left and !visited.count(root->left)) {
                findchildren(root->left, h-1, visited, ans);
            }
            if (root->right and !visited.count(root->right)) {
                findchildren(root->right, h-1, visited, ans);
            }
        }
    }
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
            // trival case
            if (K == 0) {
                return vector<int> { target->val };
            }
            // locate path from root to target
            vector<TreeNode*> path;
            findpath(root, target, path);
            // search
            unordered_set<TreeNode*> visited;
            unordered_set<TreeNode*> ans;
            int i = 0;
            while (i <= K and i < path.size()) {
                findchildren(path[i], K - i, visited, ans);
                i += 1;
            }        
            // construct result
            vector<int> rst;
            for (TreeNode* x : ans) {
                rst.push_back(x->val);
            }
            return rst;
        }
};
