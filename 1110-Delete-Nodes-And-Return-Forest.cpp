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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);  // delete root case;

        set<int> st;
        for(int i = 0; i < to_delete.size(); i++) st.insert(to_delete[i]);

        set<TreeNode*> ans;
        ans.insert(root);
        

        if(st.find(root->val) != st.end()) {
            ans.erase(root);
            if(root->left) ans.insert(root->left);
            if(root->right) ans.insert(root->right);
        }


        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);
                if(st.find(node->left->val) != st.end()) {
                    if(ans.find(node->left) != ans.end()) ans.erase(node->left);
                    if(node->left->left) ans.insert(node->left->left);
                    if(node->left->right) ans.insert(node->left->right);
                    node->left = NULL;
                }
            }
            if(node->right) {
                q.push(node->right);
                if(st.find(node->right->val) != st.end()) {
                    if(ans.find(node->right) != ans.end()) ans.erase(node->right);
                    if(node->right->left) ans.insert(node->right->left);
                    if(node->right->right) ans.insert(node->right->right);
                    node->right = NULL;
                }
            }
        }

        vector<TreeNode*> result;

        for(auto it : ans) {
            result.push_back(it);
        }

        return result;
    }
};
